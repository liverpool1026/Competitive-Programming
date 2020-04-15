#include <iostream>
#include <string>
#include <vector>
#include <map>


void populate() {
	int n, m;

	std::cin >> n >> m;
	std::vector<std::vector<int>> blackWhiteVec(n, std::vector<int>(m));
	std::vector<std::vector<char>> ruleVec(n, std::vector<char>(m));


	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		for (int j = 0; j < m; j++) {
			blackWhiteVec[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> ruleVec[i][j];
		}
	}

	std::vector<std::vector<std::pair<int, int>>> parentVec(n, std::vector<std::pair<int, int>>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = i;
			int y = j;
			if (ruleVec[i][j] == 'U') {
				x--;
			}
			if (ruleVec[i][j] == 'D') {
				x++;
			}
			if (ruleVec[i][j] == 'R') {
				y++;
			}
			if (ruleVec[i][j] == 'L') {
				y--;
			}
			parentVec[i][j] = {x, y};
		}
	}

	for (int k = 0; k < 50; k++) {
		std::vector<std::vector<std::pair<int, int>>> parentCopyVec(n, std::vector<std::pair<int, int>>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x = parentVec[i][j].first;
				int y = parentVec[i][j].second;
				parentCopyVec[i][j] = parentVec[x][y];
			}
		}
		parentVec = parentCopyVec;
	}

	std::map<std::pair<int, int>, int> mapping;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = parentVec[i][j].first;
			int y = parentVec[i][j].second;

			if (!blackWhiteVec[i][j]) {
				mapping[{x, y}] |= 1;
			} else {
				mapping[{x, y}] |= 0;
			}
		}
	}


	int count = 0;
	int blackCount = 0;

	for (auto const& x : mapping) {
		count++;
		if (x.second) {
			blackCount++;
		}
	}

	std::cout << count << " " << blackCount << std::endl;
}


int main() {
	int T;

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate();
	}


}
