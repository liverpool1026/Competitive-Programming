#include <iostream>


int main() {
	unsigned long long int N, K, Q;

	std::cin >> N >> K;
	if ((N > K && N % K == 0) || (N < K && K % N == 0)) {
		return N % K;
	}

	while (1) {

		if (N > K) {
			Q = N % K;
		} else {
			Q = K % N;
		}

		if (
		if (Q == 0) {
			return 
	}
}

