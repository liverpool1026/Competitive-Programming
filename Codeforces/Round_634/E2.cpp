#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


int solve(const std::vector<int>& vec, int i, int j) {
	int r = 0;
	int l = (int) vec.size() - 1;

	int iCount = 0;
	int jCount = std::count(vec.begin(), vec.end(), j);

	int maxValue = std::count(vec.begin(), vec.end(), i);
	while (true) {
		while (vec[r] != i && r <= l) {
			jCount--;
			r++;
		} 
		while (vec[l] != i && r <= l) {
			jCount--;
			l--;
		}

		if (!jCount) {
			break;
		}

		if (vec[l] != i || vec[r] != i) {
			break;
		}

		iCount+=2;
		maxValue = std::max(maxValue, iCount+jCount);
		r++;
		l--;
	}

	return maxValue;
}



void populate() {
	int n;
	std::cin >> n;
	std::vector<int> vec(n);
	std::map<int, std::vector<int>> count;

	for (int i = 0; i < n; i++) {
		std::cin >> vec[i];
		count[vec[i]].emplace_back(i);
	}

	for (int i = 0; i < n; i++) {
		count[vec[i]].emplace_back(n);
	}


	int max = 0;
	// Only 200 values -> brute force loop
	for (int i = 1; i < 201; i++) {
		for (int j = 1; j < 201; j++) {
			if (i == j) {
				max = std::max(count[i].size(), max);
			} else if (!count[i].size() || !count[j].size()) {
				continue;
			} else {
				std::vector<int> newVec;
				for (int a = 0, int b = 0; a < count[i].size() - 1 || b < count[j].size() - 1) {
					if (count[i][a] > count[j][b]) {
						newVec.emplace_back(j);
						b++;
					} else {
						newVec.emplace_back(i);
						a++;
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
