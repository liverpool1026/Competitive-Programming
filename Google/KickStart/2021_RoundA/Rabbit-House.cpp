#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <map>


void populate(int testCase) {
	int R, C;

	std::cin >> R >> C;

	std::map<std::pair<int, int>, int> plot;

	std::vector<std::vector<int>> dpA(R, std::vector<int>(C));
	std::vector<std::vector<int>> dpB(R, std::vector<int>(C));
	std::vector<std::vector<int>> dpC(R, std::vector<int>(C));
	std::vector<std::vector<int>> dpD(R, std::vector<int>(C));

	std::pair<int, int> maxCellPair = {0, 0};
	int maxCell = 0;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cin >> plot[{i, j}];
			if (plot[{i, j}] > maxCell) {
				maxCell = plot[{i, j}];
				maxCellPair = {i, j};
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
