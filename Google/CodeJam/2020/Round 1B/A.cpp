#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>


// std::cout << "Case #" << test << ": " << result << std::endl;

bool checkLog2(int n) {
	if (n) {
		return (n & (n - 1)) == 0;
	} else {
		return false;
	}
}

std::vector<int> getBinaryRep(int n) {
	std::string binaryRep = std::bitset<30>(n).to_string();

	std::vector<int> vec;

	for (char c : binaryRep) {
		vec.emplace_back(c - '0');
	}

	return vec;
}




void populate(int test) {
	int X, Y;
	int Xneg = 0, Yneg = 0;
	std::cin >> X >> Y;

	if ((X % 2 && Y % 2) || (!(X % 2) && !(Y % 2))) {
		std::cout << "Case #" << test << ": " << "Impossible" << std::endl;
	} else {
		if (X < 0) {
			Xneg = 1;
			X = 0 - X;
		}

		if (Y < 0) {
			Yneg = 1;
			Y = 0 - Y;
		}
			
		if (X % 2) {
			// Deal with odd number
			if (X == 1) {

		}



	}


}



int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate(i+1);
	}


}
