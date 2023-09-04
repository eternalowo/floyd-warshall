#include "floyd-warshall.h"

// A system of two - way roads is set, 
// and for any pair of cities, you can 
// specify a path connecting them. Find 
// a city for which the sum of
// distances to other cities is minimal.

int main() {
	int citycount = floyd_warshall::fill_matrix();
	floyd_warshall::floyd(citycount);
	floyd_warshall::city(citycount);
	return 0;
};
