#include <iostream>



int main() {
	const unsigned long long int LIMIT = 1e18;

	unsigned long long int a = 1;

	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		unsigned long long int b;
		std::cin >> b;
		a *= b;
		if (!a) {
			std::cout << "0" << std::endl;
			return 0;
		} else if (a > LIMIT) {
			std::cout << "-1" << std::endl;
			return 0;
		}
	}


	std::cout << a << std::endl;
	

}
