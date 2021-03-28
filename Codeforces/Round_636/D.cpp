#include <iostream>
#include <vector>
#include <map>


int populate() {
	int n, k;

	std::cin >> n >> k;

	std::vector<int> vec(n);

	for (int i = 0; i < n; i++) {
		std::cin >> vec[i];
	}

	int i = 0;
	int j = n - 1;

	std::map<int, int> entry;

	while (i<j) {
		entry[vec[i]+vec[j]]++;
		i++;
		j--;
	}


	int maxCount = 0;
	int maxValue = 0;
	for (auto x : entry) {
		if (maxCount == x.second) {
			maxValue = x.first;
		} else if (x.second > maxCount) {
			maxValue = x.first;
		}
		maxCount = std::max(x.second, maxCount);
	}

	for (int i = 0; i < n/2; i++) {
		if (k + vec[i] < maxValue && k + vec[n-1-i] < maxValue) {
			maxCount--;
		} else if (vec[i] >= maxValue && vec[n-1-i] >= maxValue) {
			maxCount--;
		}

	}
	std::cout << n/2 - maxCount<< std::endl;
	return 0;

}




int main() {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate();
	}
}
