#include "floyd-warshall.h"

namespace floyd_warshall {

	const int N = 20;
	const int INF = 99999;

	std::vector<std::vector<int>> matrix;
	std::vector<std::string> cities;

	int sum = 0;

	int fill_matrix() {
		std::ifstream input;
		input.open("input.txt");

		std::string tmp, town1, town2;

		int ctcount = 0;
		int length = 0;
		bool flag = false;

		matrix.resize(N);
		cities.resize(N);

		for (std::size_t i = 0; i < N; ++i) {
			matrix[i].resize(N);
		}

		for (std::size_t x = 0; x < N; x++) {
			for (std::size_t y = 0; y < N; y++) {
				matrix[x][y] = INF;
			}
		}

		while (!input.eof()) {

			input >> town1 >> length >> town2;

			if (!input) {
				std::cout << "Invalid input";
				input.close();
				exit(1);
			}

			int x = 0;

			for (x = 0, flag = false; x < ctcount && !flag; x++)
				if ((town1 == cities[x]))
					flag = true;

			if (flag)
				x--;

			else {
				x = ctcount;
				ctcount++;
				cities[x] = town1;
			}

			int y = 0;

			for (y = 0, flag = false; y < ctcount && !flag; y++)
				if ((town2 == cities[y]))
					flag = true;

			if (flag)
				y--;

			else {
				y = ctcount;
				ctcount++;
				cities[y] = town2;
			}

			if (length < matrix[x][y]) {
				matrix[x][y] = length;
				matrix[y][x] = length;
			}

		}

		input.close();
		return ctcount;

	};

	void floyd(int ctcount) {
		for (std::size_t p = 0; p < ctcount; p++) {
			for (std::size_t x = 0; x < ctcount; x++) {
				for (std::size_t y = 0; y < ctcount; y++) {
					if (matrix[x][y] > matrix[x][p] + matrix[p][y])
						matrix[x][y] = matrix[x][p] + matrix[p][y];
				}
			}
		}
	};

	void city(int ctcount) {

		std::ofstream output;
		output.open("output.txt");

		int minsum = INF * ctcount;
		std::size_t ind;

		for (std::size_t x = 0; x < ctcount; x++) {
			for (std::size_t y = 0; y < ctcount; y++) {
				if (x == y)
					matrix[x][y] = 0;
			}
		}

		for (std::size_t x = 0; x < ctcount; x++) {
			for (std::size_t y = 0; y < ctcount; y++) {
				sum = sum + matrix[x][y];
			}
			if (sum < minsum) {
				minsum = sum;
				ind = x;
			}
			sum = 0;
		}

		std::cout << "Shortest sum is for city: " << cities[ind];
		output << "Shortest sum is for city: " << cities[ind];
		output.close();
	};
}; // namespace floyd_warshall