#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>


std::vector<std::pair<int, int>> getAvailableOptions(std::pair<int, int> par, int S, std::unordered_map<std::pair<int, int>, int> underConstruction, std::unordered_map<std::pair<int, int>, int> paintedRoom) {
	std::vector<std::pair<int, int>> vec;

	if (par.second > 1) {
		std::pair<int, int> tempPair = std::make_pair(par.first, par.second - 1);
		if (underConstruction[tempPair] + paintedRoom[tempPair] == 0) {
			vec.push_back(tempPair);
		}
	}

	if (par.second < 2 * par.first - 1) {
		std::pair<int, int> tempPair = std::make_pair(par.first, par.second + 1);
		if (underConstruction[tempPair] + paintedRoom[tempPair] == 0) {
			vec.push_back(tempPair);
		}
	}

	if (par.first % 2) {
		std::pair<int, int> tempPair = std::make_pair(par.first + 1, par.second + 1);
		if (par.first <= S && par.second < S * 2 && underConstruction[tempPair] + paintedRoom[tempPair] == 0) {
			vec.push_back(tempPair);
		}
	} else {
		std::pair<int, int> tempPair = std::make_pair(par.first - 1, par.second - 1);
		if (par.first > 0 && par.second > 0 && underConstruction[tempPair] + paintedRoom[tempPair] == 0) {
			vec.push_back(tempPair);
		}
	}

	return vec;
}



void populate(int testCase) {

	int S, RA, PA, RB, PB, C;
	std::cin >> S >> RA >> PA >> RB >> PB >> C;

	std::unordered_map<std::pair<int, int>, int> underConstruction;
	std::unordered_map<std::pair<int, int>, int> paintedRoom;

	for (int i = 0; i < C; i++) {
		int a, b;
		std::cin >> a >> b;
		underConstruction[std::make_pair(a, b)] = 1;
	}

	std::pair<int, int> currentPairA = std::make_pair(RA, PA);
	std::pair<int, int> currentPairB = std::make_pair(RB, PB);
	
	paintedRoom[currentPairA] = 1;
	paintedRoom[currentPairB] = 1;


	int flagA = 1;
	int flagB = 1;
	int countA = 0;
	int countB = 0;
	while(flagA + flagB > 0) {
		if (flagA) {
			std::vector<std::pair<int, int>> availableOptions = getAvailableOptions(currentPairA, S, underConstruction, paintedRoom);

			if (availableOptions.empty()) {
				flagA = 0;
			} else {
				// Naviely get first option
				paintedRoom[availableOptions[0]] = 1;
				currentPairA = availableOptions[0];
				countA++;
			}
		}

		if (flagB) {
			std::vector<std::pair<int, int>> availableOptions = getBvailableOptions(currentPairB, S, underConstruction, paintedRoom);

			if (availableOptions.empty()) {
				flagB = 0;
			} else {
				// Naviely get first option
				paintedRoom[availableOptions[0]] = 1;
				currentPairB = availableOptions[0];
				countB++:
			}
		}

	}

	std::cout << "Case #" << testCase << ": " << count << std::endl;
}


int main() {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate(i+1);
	}

}
