#include <iostream>
#include <string>


int main() {

	int N;
	int array[(int)2e5+1];
	std::cin >> N;

	for (int i = 1; i < N+1; i++) {
		std::cin >> array[i];
	}

	int count = 0;

	for (int i = 1; i < N; i++) {
		int required = N - i - array[i];

		for (int j = N; j > 0; j--) {
			if (required == 0) {
				break;
			}
			if (array[j] == required) {
				count++;
			}
			required--;
		}
	}

	std::cout << count << std::endl;

}
