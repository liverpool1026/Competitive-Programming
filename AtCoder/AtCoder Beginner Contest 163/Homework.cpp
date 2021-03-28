#include <iostream>
#include <vector>


int main() {

	int N, M;
	std::cin >> N >> M;

	int totalDays = 0;

	for (int i = 0; i < M; i++) {
		int buffer;
		std::cin >> buffer;
		totalDays+=buffer;
	}


	if (totalDays > N) {
		std::cout << "-1\n";
	} else {
		std::cout << N - totalDays << std::endl;
	}



}
