#include <iostream>
#include <unordered_map>
#include <string>


int main() {

	int N, K;
	std::cin >> N >> K;

	std::unordered_map<int, int> counts;

	for (int i = 0; i < K; i++) {
		int count;
		std::cin >> count;

		for (int j = 0; j < count; j++) {
			int a;
			std::cin >> a;
			counts[a]++;
		}
	}


	int count = 0;
	for (int i = 1; i < N+1; i++) {
		if (!counts[i]) {
			count++;
		}
	}

	std::cout << count << std::endl;

}
