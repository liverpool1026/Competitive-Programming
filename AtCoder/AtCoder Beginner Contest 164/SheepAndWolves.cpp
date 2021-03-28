#include <iostream>


int main() {
	int s, w;
	std::cin >> s >> w;

	if (w >= s) {
		std::cout << "unsafe" << std::endl;
	} else {
		std::cout << "safe" << std::endl;
	}


}
