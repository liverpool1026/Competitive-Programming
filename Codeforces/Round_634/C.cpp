#include <iostream>
#include <map>


void populate() {
	int n;
	std::cin >> n;
	std::map<int, int> counts;

	for (int i = 0; i < n; i++) {
		int buffer;
		std::cin >> buffer;
		counts[buffer]++;
	}

	std::pair<int, int> maxCountNumberPair = {0, 0};
	int distinctValue = 0;

	for (auto const& x: counts) {
		distinctValue++;
		if (x.second > maxCountNumberPair.second) {
			maxCountNumberPair = {x.first, x.second};
		}
	}

	if (distinctValue - 1 >= maxCountNumberPair.second) {
		std::cout << maxCountNumberPair.second << std::endl;
	} else if (distinctValue == maxCountNumberPair.second) {
		std::cout << maxCountNumberPair.second - 1<< std::endl;
	} else {
		std::cout << distinctValue << std::endl;
	}
}


int main() {
	int T;

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate();
	}


}
