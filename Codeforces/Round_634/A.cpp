#include <iostream>


void populate() {
	int n;

	std::cin >> n;

	int count;

	if (n % 2) {
		count = (n - 1) / 2;
	} else {
		count = n / 2 - 1;
	}

	if (count < 0) {
		count = 0;
	}
		
	std::cout << count << std::endl;
}


int main() {
	int T;

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate();
	}


}
