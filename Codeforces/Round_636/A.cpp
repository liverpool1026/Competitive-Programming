#include <iostream>


int populate() {
	int n;
	std::cin >> n;

	int i = 4;

	while (true) {
		if (!(n % (i-1))) {
			std::cout << n/(i-1) << std::endl;
			return 0;
		}
		i*=2;
	}

	return 0;
}




int main() {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate();
	}
}
