#include <iostream>


long long int fizzbussSum(int n) {
	long long int sum = 0;

	for (int i = 1; i < n+1; i++) {
		if (i % 3 == 0 || i % 5 == 0) {

		} else {
			sum+=i;
		}
	}
	return sum;
}


int main() {
	int N;
	std::cin >> N;

	std::cout << fizzbussSum(N) << std::endl;
}
