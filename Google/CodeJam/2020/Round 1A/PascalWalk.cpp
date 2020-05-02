#include <iostream>

void walk(int test) {

	int i;
	std::cin >> i;
	std::cout << "Case #" << test << ":"<< std::endl;
	int startingIndex = 1;

	if (i > 500) {
		std::cout << startingIndex++ << " 1" << std::endl;
		std::cout << startingIndex++ << " 1" << std::endl;
		i-=2;
		int flag = true;
		while (i > 0) {
			if (i < startingIndex) {
				i-=1;
				if (flag) {
					startingIndex--;
					flag = false;
				}
				std::cout << startingIndex++ << " 1" << std::endl;
			} else {
				i= i - startingIndex + 1;
				std::cout << startingIndex++ << " 2" << std::endl;
			}
		}


	} else {
		for (int j = 0; j < i; j++) {
			std::cout << startingIndex++ << " 1" << std::endl;
		}
	}

}



int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		walk(i+1);
	}


}
