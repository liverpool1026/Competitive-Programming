#include <iostream>
#include <vector>


void populate(int testCase) {

	int N, K;
	std::cin >> N >> K;

	std::vector<char> vec(N+1);

	for (int i = 1; i < N + 1; i++) {
		std::cin >> vec[i];
	}

	int currentGoodnessString = 0;

	for (int i = 1; i <= N / 2; i++) {
		if (vec[i] != vec[N+1-i]) {
			currentGoodnessString++;
		}
	}

	int counts = 0;

	if (currentGoodnessString > K) {
		counts = currentGoodnessString - K;
	} else {
		counts = K - currentGoodnessString;
	}

	std::cout << "Case #" << testCase << ": " << counts << std::endl;

}


int main() {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate(i+1);
	}

}
