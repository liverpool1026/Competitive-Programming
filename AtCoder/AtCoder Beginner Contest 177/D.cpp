#include <set>
#include <vector>
#include <iostream>
#include <algorithm>


int main() {

	int N, M;

	std::cin >> N;
	std::cin >> M;

	std::vector<std::set<int>> vec(N);

	for (int i = 0; i < M; i++) {
		int x, y;
		std::cin >> x >> y;
		vec[x-1].insert(y-1);
		vec[y-1].insert(x-1);

		for (int j : vec[x-1]) {
			vec[j].insert(y-1);
		}
	}

	int count = 0;
	for (std::set<int> s : vec) {
		count = std::max(count, (int) s.size());

		for (int i : s) {
			std:: cout << i + 1<< ", ";
		}
		std::cout << "\n";

	}

	if (count == 1) {
		std::cout << 1 << std::endl;
	} else {
		std::cout << count - 1 << std::endl;
	}



	

}
