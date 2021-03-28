#include <iostream>

void populate() {
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;

	std::cout << b << " " << c << " " << c << std::endl;
}




int main() {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate();
	}
}
