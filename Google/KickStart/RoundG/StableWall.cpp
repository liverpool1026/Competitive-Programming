#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>


void populate(int testCase) {
	int R, C;

	std::cin >> R >> C;

	std::vector<std::vector<char>> wall(R, std::vector<char>(C));
	std::unordered_map<char, std::vector<std::pair<int, int>>> mapping;
	std::vector<char> doneOrder;
	std::set<char> charSet;
	


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cin >> wall[i][j];
			mapping[wall[i][j]].emplace_back(i, j);
			charSet.insert(wall[i][j]);
		}
	}

	for (auto const x : mapping) {
		std::vector<std::vector<int>> check(R, std::vector<int>(C));
		check[x.second[0].first][x.second[0].second] = 1;
		for (int i = 1; i < x.second.size(); i++) {
			int x_ = x.second[i].first;
			int y = x.second[i].second;
			bool check_ = false;

			if (x_) {
				if (check[x_-1][y]) {
					check_ = true;
				}
			}
			if (y) {
				if (check[x_][y-1]) {
					check_ = true;
				}
			}

			if (!check_) {
				std::cout << x_ << "~" << y << "\n";
				std::cout << "Case #" << testCase << ": -1" << std::endl;
				return;

			}
			check[x_][y] = 1;
		}
	}



	std::vector<std::vector<int>> wallCheck(R, std::vector<int>(C));
	for (int i = R - 1; i >= 0; i--) {
		std::vector<char> entries;
		for (int j = 0; j < C; j++) {
			if (std::find(entries.begin(), entries.end(), wall[i][j]) == entries.end()) {
				entries.emplace_back(wall[i][j]);
			}
		}
		for (char c : entries) {
			std::vector<std::vector<int>> wallCheckCopy(wallCheck);
			//std::cout << "Current Entry: " << c << "\n";
			if (std::find(doneOrder.begin(), doneOrder.end(), c) != doneOrder.end()) {
				continue;
			}
			std::vector<std::pair<int, int>> cVec = mapping[c];
			std::sort(cVec.begin(), cVec.end(), [] (const std::pair<int, int>& par1, const std::pair<int, int>& par2) {
					if (par1.first != par2.first) {
						return par1.first > par2.first;
 					} else {
					       return par1.second < par2.second;
	 			        }
				
			});
			int done = 1;

			for (std::pair<int, int> par : cVec) {
				//std::cout << par.first << "~~~" <<  par.second << "\n";
				if (par.first == R - 1) {
					wallCheckCopy[par.first][par.second] = 1;
				} else {
					if (wallCheckCopy[par.first + 1][par.second]) {
						wallCheckCopy[par.first][par.second] = 1;
					} else {
						done = 0;
						//std::cout << "There" << par.first << "~" << par.second << "\n";
						break;
					}
				}

				//std::cout << "\n";

				/*
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						std::cout << wallCheckCopy[i][j] << " ";
					}
					std::cout << "\n";
				}*/
			}

			if (done && wallCheckCopy[R-1][0]) {
				int flag = 0;
				for (int i = 1; i < C; i++) {
					if (flag && wallCheckCopy[R-1][i]) {
						done = 0;
					}
					if (!wallCheckCopy[R-1][i]) {
						flag = 1;
					}
				}
			}
			if (done && wallCheckCopy[R-1][C-1]) {
				int flag = 0;
				for (int i = C-2; i >= 0; i--) {
					if (flag && wallCheckCopy[R-1][i]) {
						done = 0;
					}
					if (!wallCheckCopy[R-1][i]) {
						flag = 1;
					}
				}
			}

			if (done) {
				doneOrder.emplace_back(c);
				wallCheck = wallCheckCopy;
			}

		}
	}

	while (1) {
		int currentSize = doneOrder.size();

		for (char c: charSet) {
			std::vector<std::vector<int>> wallCheckCopy(wallCheck);
//			std::cout << "Current Entry: " << c << "\n";
			if (std::find(doneOrder.begin(), doneOrder.end(), c) != doneOrder.end()) {
				continue;
			}
			std::vector<std::pair<int, int>> cVec = mapping[c];
			std::sort(cVec.begin(), cVec.end(), [] (const std::pair<int, int>& par1, const std::pair<int, int>& par2) {
					if (par1.first != par2.first) {
						return par1.first > par2.first;
					} else {
					       return par1.second < par2.second;
					}
				
			});
			int done = 1;

				for (std::pair<int, int> par : cVec) {
					//std::cout << par.first << "~~~" <<  par.second << "\n";
					if (par.first == R - 1) {
						wallCheckCopy[par.first][par.second] = 1;
					} else {
						if (wallCheckCopy[par.first + 1][par.second]) {
							wallCheckCopy[par.first][par.second] = 1;
						} else {
							done = 0;
//							std::cout << "There" << par.first << "~" << par.second << "\n";
							break;
						}
					}

//					std::cout << "\n";

					/*
					for (int i = 0; i < R; i++) {
						for (int j = 0; j < C; j++) {
							std::cout << wallCheckCopy[i][j] << " ";
						}
						std::cout << "\n";
					}*/
				}

				if (done && wallCheckCopy[R-1][0]) {
					int flag = 0;
					for (int i = 1; i < C; i++) {
						if (flag && wallCheckCopy[R-1][i]) {
							done = 0;
						}
						if (!wallCheckCopy[R-1][i]) {
							flag = 1;
						}
					}
				}
				if (done && wallCheckCopy[R-1][C-1]) {
					int flag = 0;
					for (int i = C-2; i >= 0; i--) {
						if (flag && wallCheckCopy[R-1][i]) {
							done = 0;
						}
						if (!wallCheckCopy[R-1][i]) {
							flag = 1;
						}
					}
				}

				if (done) {
					doneOrder.emplace_back(c);
					wallCheck = wallCheckCopy;
				}

			}
		 
		if(doneOrder.size() == currentSize) {
			break;
		}
		}


	if (doneOrder.size() != charSet.size()) {
		for (char c : doneOrder) {
			std::cout << c << " ";
		}
		std::cout << "Case #" << testCase << ": -1" << std::endl;
	} else {
		std::cout << "Case #" << testCase << ": " << std::string(doneOrder.begin(), doneOrder.end()) << std::endl;
	}







}


int main() {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate(i+1);
	}

}
