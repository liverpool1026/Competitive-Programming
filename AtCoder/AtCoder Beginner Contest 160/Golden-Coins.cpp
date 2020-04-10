#include <iostream>


int main() {

	int yen;
	std::cin >> yen;

	int fiveHundred = yen / 500;

	yen -= fiveHundred * 500;

	std::cout << fiveHundred * 1000 + 5 * (yen / 5);


}
