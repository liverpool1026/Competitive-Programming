#include <iostream>

int gcd(int a, int b, int c) {
	// a is the biggest
	for (int i = c; i > 0; i--) {
		if ((a % i) + (b % i) + (c % i) == 0) {
			return i;
		}
	}

	return 1;
}


int sumOfgcd(int n) {
	if (n == 1) {
		return 1;
	} else {
		int count = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (j != i) {
					count += 6 * gcd(n, j, i);
				} else {
					count += 3 * gcd(n, j, i);
				}
			}
			count += 3 * gcd(n, n, i); // n
		}
		return sumOfgcd(n-1) + count + n;
	}
}


int main() {
	int N;
	std::cin >> N;

	std::cout << sumOfgcd(N) << std::endl;
}
