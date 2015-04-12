#include "quadtree.h"

#include <iostream>
using namespace std;

template<class T>
quadtree<T>* quadtree<T>::insert_(T data, point p, quadtree<T>* tree){
	if (LEAF(tree,T)){
		qleaf<T>* leaf = static_cast<qleaf<T>*>(tree);
		if (leaf->bucket.size() < leaf->threshold){
			// add item into bucket
			struct qdatum<T> q = {data, p};
			leaf->bucket.push_back(q);
			return tree;
		} else {
			// overflow, we need to resize into 4 quads
			quadtree<T>* node = new quadtree<T>(tree->bounding_box);
			// Note: as long as threshold is low compared to the density of the tree, all ops should be at log(n)
			while (!leaf->bucket.empty()){
				struct qdatum<T> cur = leaf->bucket.back();
				leaf->bucket.pop_back();
				node->insert(cur.data, cur.p);
			}
			delete leaf;
			return node;
		}
	} else {
		tree->insert(data, p);
		return tree;
	}
}

template<class T>
bool quadtree<T>::insert(T data, point p){
	//insert_(data, p, nw);
	if (nw->bounding_box.contains(p)){
		nw = insert_(data, p, nw);
	} else if (ne->bounding_box.contains(p)){
		ne = insert_(data, p, ne);
	} else if (sw->bounding_box.contains(p)){
		sw = insert_(data, p, sw);
	} else if (se->bounding_box.contains(p)){
		se = insert_(data, p, se);
	} else {
		return false; // out of bounds
	}
	return true;
}

template<class T>
bool quadtree<T>::insert(T data, int x, int y){
	point p = {x,y};
	return insert(data, p);
}

template<class T>
template<class S>
S* quadtree<T>::fold(std::function<S*(T data, point p, S*)> function, S* acc, rectangle area){
	if (!bounding_box.intersects(area)) return acc;
	if(LEAF(this, T)){
		qleaf<T>* leaf = static_cast<qleaf<T>*>(this);
		// fold over the current bucket
		list<qdatum<T>>::iterator it;
		it = leaf->bucket.begin();
		size_t i;
		for(i=0;i<leaf->bucket.size(); i++, it++){
			qdatum<T> current = *it;
			if (area.contains(current.p)){
				acc = function(current.data, current.p, acc);
			}
		}
		return acc;
	} else {
		
		acc = this->nw->fold(function, acc, area);
		acc = this->ne->fold(function, acc, area);
		acc = this->sw->fold(function, acc, area);
		acc = this->se->fold(function, acc, area);
		return acc;
	}
}

template<class T>
template<class S>
S* quadtree<T>::fold(S*(*fun)(T, point, S*), S* acc, rectangle area){
	return fold<S>([fun](T d, point p, S* a)->S*{return fun(d, p, a);}, acc, area);
}

template<class T>
template<class S>
std::list<qdatum<S>> quadtree<T>::map(std::function<S(T)> fun, rectangle area){
	std::list<qdatum<S>>* list = new std::list<qdatum<S>>();
	fold<std::list<qdatum<S>>>([fun](T d, point p, std::list<qdatum<S>>* list) -> std::list<qdatum<S>>*{
		qdatum<S> cur = {fun(d), p};
		list->push_back(cur);
		return list;
	}, list, area);

	return *list;
}

template<class T>
template<class S>
std::list<qdatum<S>> quadtree<T>::map(S(*fun)(T), rectangle area){
	return map<S>([fun](T d)->S{return fun(d);}, area);
}

template<class T>
std::list<qdatum<T>> quadtree<T>::to_list(rectangle area){
	return this->map<T>([](T d)->T{return d;}, area);
}

template<class T>
std::list<qdatum<T>> quadtree<T>::to_list(){
	return to_list(bounding_box);
}
