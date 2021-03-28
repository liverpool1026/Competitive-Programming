#include <iostream>
#include <vector>


void populate() {
	int n;
	std::cin >> n;

	if (n % 4) {
		std::cout << "NO" << std::endl;
	} else {
		std::cout << "YES" << std::endl;
		for (int i = 0; i < n / 2; i++) {
			std::cout << (i + 1) * 2 << " ";
		}

		for (int i = 0; i < n/2 -1; i++) {
			std::cout << (i * 2 + 1) << " ";
		}

		std::cout << n + n / 2 -1 << std::endl;
	}




}




int main() {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate();
	}
}
