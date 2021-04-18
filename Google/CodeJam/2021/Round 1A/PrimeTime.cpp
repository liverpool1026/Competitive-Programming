#include <vector>
#include <string>
#include <iostream>


void optimise(int test) {

	int i;
	int ops = 0;
	std::cin >> i;
	std::vector<unsigned long long> vec(i);

	for (int x = 0; x < i; x++) {
		std::cin >> vec[x];
	}


	for (int x = 0; x < i-1; x++) {
		ops += operations(vec, x);
	}

	std::cout << "Case #" << test << ": "<< ops << std::endl;
}



int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		optimise(i+1);
	}


}
