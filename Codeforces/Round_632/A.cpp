#include <iostream>


void goodColoring() {
	int col, row;

	std::cin >> row >> col;


	if (row > 1 && col > 1) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (i == 0 && j == 0) {
					std::cout << "W";
				} else {
					std::cout << "B";
				}
			}
			std::cout << std::endl;
		}
	}

}




int main() {
	int testCases;

	std::cin >> testCases;

	for (int i = 0; i < testCases; i++) {
		goodColoring();

	}

}
