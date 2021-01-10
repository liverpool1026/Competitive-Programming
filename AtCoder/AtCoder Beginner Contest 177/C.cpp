#include <iostream>
#include <vector>

const long long int MOD = 1e9 + 7;


int main() {
	int a;

	std::cin >> a;


	std::vector<long long int> vec(a);

	long long int sum = 0;

	for (int i = 0; i < a; i++) {
		std::cin >> vec[i];
		sum += vec[i];
	}

	long long int c = 0;

	for (int i = 0; i < a; i++) {
		sum -= vec[i];
		c = ((c % MOD) +  ( (vec[i] % MOD) * (sum % MOD) ) % MOD) % MOD;
	}


	std::cout << c << std::endl;

}
