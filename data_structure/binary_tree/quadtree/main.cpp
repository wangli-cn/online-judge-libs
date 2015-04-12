// simple test run
#include "quadtree.h"

int main(){
	quadtree<int>* tree = new quadtree(rectangle(0, 0, 100, 100)); // initialize a quadtree occupying the square with size 100
	// blah blah tree->insert(integer, x, y);

	// we need to get the list of all points in a particular region
	std::list<qdatum<int>>  list = tree->to_list(region);

	// we want to map a function or a lambda onto all of the points in a particular region
std::list<qdatum<float>> float_list = tree->map<float>([](int x)->float{return (float)x;}, region);

	// or, we want to fold/reduce the tree into some accumulator through some function (http://en.wikipedia.org/wiki/Fold_%28higher-order_function%29)
	// sum everything in some region
	int sum = 0;
	tree->fold<int>([](int i, point p, int* acc){(*acc)+=i;return acc;}, &sum, region);

	return 0;
}