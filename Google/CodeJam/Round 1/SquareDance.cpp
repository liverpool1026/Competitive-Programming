#include <iostream>
#include <vector>
#include <map>


bool checkFinish(const std::vector<std::vector<int>>& vec, std::map<std::pair<int, int>, std::vector<std::pair<int,int>>>& neighbour, int c, int r) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (vec[i][j] != -1) {
				int size = (int) neighbour[{i, j}].size();
				int count = 0;
				for (std::pair<int, int>& pos : neighbour[{i, j}]) {
					if (pos.first == -1 && pos.second == -1) {
						count++;
					} else if (vec[pos.first][pos.second] == -1) {
						int flag = 0;
						if (pos.first == i) {
							if (pos.second > j) {
								for (int k = pos.second; k < c; k++) {
									if (vec[i][k] != -1) {
										pos.second = k;
										flag = 1;
										break;
									}
								}
							} else {
								for (int k = pos.second; k >= 0; k--) {
									if (vec[i][k] != -1) {
										pos.second = k;
										flag = 1;
										break;
									}
								}
							}
						} else {
							if (pos.first > i) {
								for (int k = pos.first; k < r; k++) {
									if (vec[k][j] != -1) {
										pos.first = k;
										flag = 1;
										break;
									}
								}
							} else {
								for (int k = pos.first; k >= 0; k--) {
									if (vec[k][j] != -1) {
										pos.first = k;
										flag = 1;
										break;
									}
								}
							}
						}

						if (!flag) {
							count++;
							pos.first = -1;
							pos.second = -1;
						}

					}
				}
				if (count == size) {
					return true;
				}
			}
		}
	}
	return false;
}



int startRound(std::vector<std::vector<int>>& vec, const std::vector<std::vector<int>>& copy, const std::map<std::pair<int, int>, std::vector<std::pair<int,int>>>& neighbour, int c, int r) {
	int total = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int value = 0;
			int count = 0;
			if (vec[i][j] != -1) {
				for (std::pair<int, int> compass : neighbour.at({i, j})) {
					if (compass.first != -1 && compass.second != -1) {
						count++;
						value += copy[compass.first][compass.second];
					}
				}

				if (vec[i][j] * count < value) {
					vec[i][j] = -1;
				} else {
					total+=vec[i][j];
				}
			}
		}
	}
	return total;
}



int compete(int test) {
	int c, r;
	int interestLevel = 0;
	std::cin >> r >> c;
	std::vector<std::vector<int>> vec(c, std::vector<int>(r));
	std::map<std::pair<int, int>, std::vector<std::pair<int,int>>> compassNeighbours;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			std::cin >> vec[i][j];
			interestLevel += vec[i][j];

			if (i != 0) {
				compassNeighbours[{i, j}].push_back({i-1, j});
			}
			if (j != 0) {
				compassNeighbours[{i, j}].push_back({i, j-1});
			}
			if (i != r - 1) {
				compassNeighbours[{i, j}].push_back({i+1, j});
			}
			if (j != c - 1) {
				compassNeighbours[{i, j}].push_back({i, j+1});
			}
		}
	}

	if (r * c == 1) {
		std::cout << "Case #" << test << ": " << interestLevel << std::endl;
		return 0;
	}

	bool finished = false;

	while (!finished) {
		std::vector<std::vector<int>> copy(vec.begin(), vec.end());
		interestLevel+=startRound(vec, copy, compassNeighbours, c, r);
		finished = checkFinish(vec, compassNeighbours, c, r);
	}
	
	std::cout << "Case #" << test << ": " << interestLevel << std::endl;
	return 0;
}


int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		compete(i+1);
	}


}
