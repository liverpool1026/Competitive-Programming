#include <iostream>
#include <vector>


int main() {

	int N, M;
	std::cin >> N >> M;
	std::vector<int> poll;

	int total = 0;

	for (int i = 0; i < N; i++) {
		int buffer;
		std::cin >> buffer;
		poll.push_back(buffer);
		total += buffer;
	}

	int count = 0;

	for (int i : poll) {
		if (i * 4 * M >= total) {
			count++;
		}
		if (count == M) {
			std::cout << "Yes";
			return 0;
		}
	}

	std::cout << "No";

}
