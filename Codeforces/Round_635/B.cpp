#include <iostream>

void populate() {
	int h, n, m;
	std::cin >> h >> n >> m;

	if (h < 20) {
		if (m * 10 >= h) {
			std::cout << "YES" << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	} else {
		int i = 0;
		while (h > 20 && i != n) {
			for (i = 0; i < n; i++) {
				h = h / 2 + 10;
			}
		}

		if (m * 10 >= h) {
			std::cout << "YES" << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	}
}




int main() {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate();
	}
}
