#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


int solve(const std::vector<int>& vec, int i, int j) {
	std::vector<int>::const_iterator it = vec.begin();
	std::vector<int>::const_reverse_iterator rit = vec.rbegin();

	int iCount = 0;
	int jCount = std::count(vec.begin(), vec.end(), j);

	int maxValue = std::count(vec.begin(), vec.end(), i);
	while (it != rit.base() - 1 && it != vec.end() && rit != vec.rend()) {
		if (*it != i) {
			jCount--;
			it++;
		} 
		if (*rit != i) {
			jCount--;
			rit++;
		}

		if (!jCount) {
			break;
		}

		if (*rit == i && *it == i) {
			iCount+=2;
			maxValue = std::max(maxValue, iCount+jCount);
			it++;
			rit++;
		}

	}

	return maxValue;
}



void populate() {
	int n;
	std::cin >> n;
	std::vector<int> vec(n);
	std::map<int, int> count;

	for (int i = 0; i < n; i++) {
		std::cin >> vec[i];
		count[vec[i]]++;
	}


	int max = 0;
	// Only 200 values -> brute force loop
	for (int i = 1; i < 27; i++) {
		for (int j = 1; j < 27; j++) {
			if (i == j) {
				max = std::max(count[i], max);
			} else if (count[i] == 0 && count[j] == 0) {
				
			} else if (count[i] == 0) {
				max = std::max(count[j], max);
			} else if (count[j] == 0) {
				max = std::max(count[i], max);
			} else {
				std::vector<int> newVec;
				for (int k : vec) {
					if (k == i) {
						newVec.emplace_back(i);
					} else if (k == j) {
						newVec.emplace_back(j);
					}
				}
				max = std::max(max, solve(newVec, i, j));
			}
		}
	}

	std::cout << max << std::endl;


}


int main() {
	int T;

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate();
	}


}
