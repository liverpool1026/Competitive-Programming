#include<iostream>


int main() {
	unsigned long long int H, W;
	std::cin >> H;
	std::cin >> W;

	unsigned long long int oddCount = 0, evenCount = 0;
	if (H == 1 || W == 1) {
		std::cout << 1;
		return 0;
	}

	oddCount = H / 2 + H % 2;
	evenCount = H / 2;

	unsigned long long int totalCount = oddCount * (W / 2 + W % 2) + evenCount * (W / 2);

	std::cout << totalCount;
}


// Solution Formula
// H & W + 1 / 2
