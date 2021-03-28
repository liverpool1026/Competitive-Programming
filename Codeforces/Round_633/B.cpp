#include <iostream>
#include <algorithm>
#include <vector>


void populate() {
	int n;
	std::cin >> n;

	std::vector<int> vec(n);

	for (int i = 0; i < n; i++) {
		std::cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end());

	int rIndex = (int) vec.size() / 2;
	int lIndex = rIndex - 1;

	int flag = 1;
	std::vector<int> result;

	while (rIndex < vec.size() && lIndex >= 0) {
		if (flag) {
			result.emplace_back(vec[rIndex++]);
			flag = 0;
		} else {
			result.emplace_back(vec[lIndex--]);
			flag = 1;
		}
	}

	if (flag && rIndex < vec.size()) {
		result.emplace_back(vec[rIndex++]);
		flag = 0;
	} else if (!flag && lIndex >= 0) {
		result.emplace_back(vec[lIndex--]);
		flag = 1;
	}

	std::cout << std::endl;
	for (int i : result) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}



int main() {
	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++) {
		populate();
	}
}
