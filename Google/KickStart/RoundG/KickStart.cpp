#include <iostream>
#include <vector>


void populate(int testCase) {

	int N, K;
	std::cin >> N >> K;

	std::vector<int> vec(N);

	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}

	int currentIndex = vec[0];

	int counts = 0;
	int flag = 0;

	for (int i = 0; i < N; i++) {
		if (vec[i] == K) {
			currentIndex = vec[i];
			flag = 1;
		} else {
			if (flag) {
				if (vec[i] != currentIndex - 1) {
					flag = 0;
				} else {
					currentIndex = vec[i];
					if (currentIndex == 1) {
						counts++;       
					}
				}
			}
		}

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
