#include <iostream>

int main() {
	unsigned long long int a, b, c;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	// Can be rewritten as 
	// std::cin >> a >> b >> c;

	if (c < b || c < a) {
		// Note: as we are taking the square and c-a-b > 2 * sqrt(ab)
		// Which indicates that c-a-b must be >= 0
		std::cout << "No";
	} else if (4 * a * b < (c - a - b) * (c - a - b)) {
		std::cout << "Yes";
	} else {
		std::cout << "No";
	}

}
