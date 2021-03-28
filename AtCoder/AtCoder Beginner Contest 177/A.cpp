#include <iostream>



int main() {
	int D, T, S;
	std::cin >> D >> T >> S;

	if (S * T >= D) {
		std::cout << "Yes" << std::endl;
	} else {
		std::cout << "No" << std::endl;
	}

}



