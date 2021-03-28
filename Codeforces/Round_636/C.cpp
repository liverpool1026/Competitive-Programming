#include <iostream>
#include <vector>

void populate() {

	int n;
	std::cin >> n;

	std::vector<long long int> vec(n);

	for (long long int i = 0; i < n; i++) {
		std::cin >> vec[i];
	}

	long long int sum = 0;
	long long int flag = 0;
	long long int currentPos = 0;
	long long int currentNeg = 0;

	if (vec[0] < 0) {
		flag = 1;
	}

	for (long long int i : vec) {
		if (flag) {
			if (i < 0) {
				if (currentNeg) {
					currentNeg = std::max(currentNeg, i);
				} else {
					currentNeg = i;
				}
			} else {
				sum += currentNeg;
				currentNeg = 0;
				flag = 0;
				currentPos = i;
			}
		} else {
			if (i > 0) {
				currentPos = std::max(currentPos, i);
			} else {
				sum += currentPos;
				currentPos = 0;
				flag = 1;
				currentNeg = i;
			}
		}
	}


	sum = sum + currentNeg + currentPos;

	std::cout << sum << std::endl;

}




int main() {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate();
	}
}
