#include <algorithm>
#include <iostream>
#include <vector>


int check() {
	long long int n, x;
	long long int total = 0;
	std::vector<int> vec;
	std::cin >> n >> x;
	bool allBelow = true;

	for (int i = 0; i < n; i++) {
		int buffer;
		std::cin >> buffer;
		vec.push_back(buffer);
		if (buffer >= x) {
			allBelow = false;
		}
		total+=buffer;
	}

	if (total >= x * n) {
		std::cout << n << std::endl;
		return 0;
	}

	if (allBelow) {
		std::cout << 0 << std::endl;
		return 0;
	}

	long long int possibleCount = total / x;
	std::sort(vec.begin(), vec.end());

	while (true) {
		long long int copy = total;

		for (int i = 0; i < n - possibleCount; i++) {
			copy -= vec[i];
		}
		
		if (possibleCount == copy / x) {
			std::cout << possibleCount << std::endl;
			return 0;
		}
	       possibleCount = copy / x;	
	}


}



int main() {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; i++) {
		check();
	}

}
