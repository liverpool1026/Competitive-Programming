#include <iostream>
#include <vector>


int main() {

	int N;
	std::cin >> N;

	std::vector<int> vec(N);

	for (int i = 0; i < N-1; i++) {
		int buffer;
		std::cin >> buffer;
		vec[buffer-1]++;
	}


	for (int i = 0; i < N; i++) {
		std::cout << vec[i] << std::endl;
	}


}
