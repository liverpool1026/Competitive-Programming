#include<iostream>

int main() {
	int N, M;

	std::cin >> N;
	std::cin >> M;

	// To be even, must be odd + odd or even + even
	
	int evenCount = 0;
	int oddCount = 0;

	if (N > 1) {
		int buffer = 1;
		for (int i = N; i > N - 2; i--) {
			buffer *= i;
		}

		evenCount = buffer / 2;
	}

	if (M > 1) {
		int buffer = 1;
		for (int i = M; i > M - 2; i--) {
			buffer *= i;
		}

		oddCount = buffer / 2;
	}

	std::cout << evenCount + oddCount;

	return 0;
}


// Solution

int main() {
	int N, M;
	std::cin >> N >> M;

	std::cout << N * (N - 1) / 2 + M * (M - 1) / 2 << "\n";

	return 0;
}
