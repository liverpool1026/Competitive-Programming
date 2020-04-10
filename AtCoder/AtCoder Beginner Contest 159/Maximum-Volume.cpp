#include <iostream>

int main() {
	float L;

	// Max when l == w == h
	std::cin >> L;

	std::cout << std::fixed << (10E9 * L * L * L / 27) / 10E9;

	return 0;
}
