#include <iostream>
#include <vector>

long long int mod(long long int a) {
	return a % (long long int) (1e9 + 7);
}


long long int possibleCombination(long long int n, long long int i) {
	long long int min;
	long long int max;
	if (i % 2) {
		min = ((i-1) / 2) * i;
		max = ((2 *n - i + 1)/2) * i;
	} else {
		min = (i-1) * (i/2);
		max = (2 *n - i + 1) * (i/2);
	}

	return max - min + 1;

}


int main() {
	int N, K;

	std::cin >> N >> K;

	long long int sum = 0;
	for (int i = K; i <= N +1; i++) {
		sum = mod(mod(sum) + mod(possibleCombination((long long int) N, (long long int) i))); 
	}


	std::cout << sum << std::endl;


}
