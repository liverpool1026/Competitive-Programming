#include <iostream>


int main() {
	unsigned long long int X;
	int K, copy;
	int currentCount = 9;
	int digit = 0;

	std::cin >> K;
	copy = K;

	if (K < 12) {
		return K;
	}

	copy -= currentCount;

	while (1) {
		digit++;
		currentCount = currentCount * 3;
		copy -= currentCount;
		if (copy < 0) {
			break;
		}
	}


	currentCount = 0
	for (int i = 0; i < digit-1; i++) {
		int buffer = 9;
		for (int j = 0; j < i; j++) {
			buffer *= 3;
		}
		currentCount += buffer;
	}

	K -= currentCount;

	int counter = 0;

	for (int i = 0; i < digit; i++) {
		counter++;
		if (K - 

		





}
