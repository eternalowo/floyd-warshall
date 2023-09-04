#ifndef FLOYD_WARSHALL_H_
#define FLOYD_WARSHALL_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

namespace floyd_warshall {

	int fill_matrix();
	void floyd(int ctcount);
	void city(int ctcount);

}; // namespace floyd_warshall

#endif
