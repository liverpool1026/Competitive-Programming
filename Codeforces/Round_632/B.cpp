#include <iostream>
#include <vector>


int matchArray() {
	int numOfElement;
	std::vector<int> arrayA;
	std::vector<int> arrayB;

	std::cin >> numOfElement;

	for (int i = 0; i < numOfElement; i++) {
		int b;
		std::cin >> b;
		arrayA.push_back(b);
	}

	for (int i = 0; i < numOfElement; i++) {
		int b;
		std::cin >> b;
		arrayB.push_back(b);
	}

	if (arrayB[0] != arrayA[0]) {
		std::cout << "NO" << std::endl;
		return 0;
	} else {
		for (int i = 0; i < numOfElement; i++) {
			if (arrayA[i] > arrayB[i]) {
				int flag = 0;
				for (int j = 0; j < i; j++) {
					if (arrayA[j] < 0) {
						flag = 1;
						break;
					}
				}
				if (!flag) {
					std::cout << "NO" << std::endl;
					return 0;
				}
			} else if (arrayA[i] < arrayB[i]) {
				int flag = 0;
				for (int j = 0; j < i; j++) {
					if (arrayA[j] > 0) {
						flag = 1;
						break;
					}
				}
				if (!flag) {
					std::cout << "NO" << std::endl;
					return 0;
				}
			}
		}
	}

	std::cout << "YES" << std::endl;
	return 0;
	
}




int main() {
	int testCases;

	std::cin >> testCases;

	for (int i = 0; i < testCases; i++) {
		matchArray();

	}

}
