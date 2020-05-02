#include <iostream>
#include <bitset>
#include <string>


void walk(int test) {

	int i;
	std::cin >> i;


	std::cout << "Case #" << test << ":"<< std::endl;
	int startingIndex = 1;
	int fullStepUntil = 0;

	if (i > 500) {
		i -= 30;
		int count = 0;
		int direction = 1;
		std::string bitRepresentation = std::bitset<30>(i).to_string();

		for (int j = 29; j >= 0; j--) {
			if (bitRepresentation[j] == '1') {
				count++;
				if (direction) {
					for (int k = 1; k < 31 - j; k++) {
						std::cout << 30 - j << " " << k << std::endl;
					}
					direction = 0;
				} else {
					for (int k = 30 - j; k > 0; k--) {
						std::cout << 30 - j << " " << k << std::endl;
					}
					direction = 1;
				}
			} else {
				if (direction) {
					std::cout << 30 - j << " 1" << std::endl;
				} else {
					std::cout << 30 - j << " " << 30 - j << std::endl;
				}
			}
		}

		for (int a = 0; a < count; a++) {
			if (direction) {
				std::cout << 31 + a << " 1" << std::endl;
			} else {
				std::cout << 31 + a << " " << 31 + a << std::endl;
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
