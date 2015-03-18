#ifndef QUADTREE_H
#define QUADTREE_H

#include <list>
#include <functional>

typedef struct point{
	int x,y;
} point;


template<class T>
struct qdatum{
	T data;
	point p;
};

class rectangle{
public:
	int x1, y1, x2, y2;
	rectangle(){};
	rectangle(int x1, int y1, int x2, int y2) : 
		x1(x1), y1(y1), x2(x2), y2(y2){};
	rectangle(point begin, point end) :
		x1(begin.x), y1(begin.y), x2(end.x), y2(end.y){};

#define avg(a,b) (((a)+(b))/2)

	inline rectangle nw(){return rectangle(x1, avg(y1,y2), avg(x1,x2), y2);}
	inline rectangle ne(){return rectangle(avg(x1,x2), avg(y1,y2), x2, y2);}
	inline rectangle se(){return rectangle(avg(x1,x2), y1, x2, avg(y1,y2));}
	inline rectangle sw(){return rectangle(x1, y1, avg(x1,x2), avg(y1,y2));}

#undef avg

	inline bool contains(int x, int y){ return x1 <= x && x <= x2 && y1 <= y && y <= y2; }
	bool contains(point p){ return contains(p.x, p.y); }

	bool intersects(rectangle other){
#define interval_intersects(x1, x2, y1, y2) ((x1 <= y1 && y1 <= x2) || (y1 <= x1 && x1 <= y2))
		return (interval_intersects(x1, x2, other.x1, other.x2)) &&
			(interval_intersects(y1, y2, other.y1, other.y2));
#undef interval_intersects
	}

	void extend(int x, int y){
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
		x1 = min(x,x1);
		y1 = min(y,y1);
		x2 = max(x,x2);
		y2 = max(y,y2);
#undef max
#undef min
	}
};

template<class T>
class quadtree{
public:
	// four quadrants
	rectangle bounding_box;
	
	quadtree(rectangle& box){
		bounding_box = box;
		nw = new qleaf<T>(box.nw());
		ne = new qleaf<T>(box.ne());
		sw = new qleaf<T>(box.sw()); 
		se = new qleaf<T>(box.se());}

	bool insert(T, point);
	bool insert(T, int, int);

	template<class S>
	S* fold(S*(*)(T, point, S*), S*, rectangle);
	template<class S>
	S* fold(std::function<S*(T data, point p, S*)>, S*, rectangle);
	template<class S>
	std::list<qdatum<S>> map(S(*)(T), rectangle area);
	template<class S>
	std::list<qdatum<S>> map(std::function<S(T)>, rectangle area);

	std::list<qdatum<T>> to_list();
	std::list<qdatum<T>> to_list(rectangle area);

	std::list<qdatum<T>> filter(std::function<bool(T, point)>, rectangle area);
	std::list<qdatum<T>> filter(bool(*)(T, point), rectangle area);

	virtual ~quadtree(){};

private:
	quadtree<T>* insert_(T, point, quadtree<T>*);
	quadtree<T> *nw, *ne, *sw, *se;

protected:
	quadtree(){};
};


template<class T>
class qleaf : public quadtree<T>{
public:
	static const int threshold = 10;
	// data and point
	std::list<struct qdatum<T>> bucket;

	qleaf(rectangle box){
		bounding_box = box;
	}

private:
	bool insert(T, point){return false;}
	bool insert(T, int, int){return false;}
};

#define LEAF(q,t) (dynamic_cast<qleaf<t>*>(q))

#endif