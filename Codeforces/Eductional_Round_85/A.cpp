#include <iostream>


int check() {
	int times;
	std::cin >> times;

	int currentAttempts = 0;
	int currentClears = 0;
	int failed = 0;
	int flag = 1;

	for (int i = 0; i < times; i++) {
		int attempt, clear;
		std::cin >> attempt >> clear;

		if (flag) {

			if (clear > attempt || attempt - clear < failed || attempt < currentAttempts || currentClears > clear) {
				std::cout << "NO" << std::endl;
				flag = 0;
			}

			currentAttempts = attempt;
			currentClears = clear;
			failed = currentAttempts - currentClears;
		}
	}

	if (flag) {
		std::cout << "YES" << std::endl;
	}
		
	return 0;
}



int main() {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; i++) {
		check();
	}

}
