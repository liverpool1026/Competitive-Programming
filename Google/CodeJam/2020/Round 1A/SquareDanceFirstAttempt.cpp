#include <iostream>
#include <vector>
#include <map>


bool check(const std::vector<std::vector<int>>& vec, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int count = 0;

			if (i) {
				for (int k = i - 1; k >= 0; k--) {
					if (vec[k][j] != -1) {
						count++;
						break;
					}
				}
			}

			if (i != r-1) {
				for (int k = i + 1 ; k < r; k++) {
					if (vec[k][j] != -1) {
						count++;
						break;
					}
				}
			}

			if (j) {
				for (int k = j - 1; k >= 0; k--) {
					if (vec[i][k] != -1) {
						count++;
						break;
					}
				}
			}

			if (j != c-1) {
				for (int k = j + 1 ; k < c; k++) {
					if (vec[i][k] != -1) {
						count++;
						break;
					}
				}
			}
			if (count == 0) {
				return false;
			}
		}
	}

	return true;
}


bool round(std::vector<std::vector<int>> vec, std::vector<std::vector<int>>& modify, int r, int c, std::map<std::pair<int, int>,std::vector<std::pair<int,int>>>& abc, int x, int y) {
	int totalValue = 0;
	int count = 0;

	std::vector<std::pair<int,int>>::iterator it = abc[{x, y}].begin();

	while (it != abc[{x, y}].end()) {
		std::pair<int, int> pos = *it;
		if (vec[pos.first][pos.second] != -1) {
			totalValue += vec[pos.first][pos.second];
			count++;
			it++;
		} else {
			int found = 0;
			if (pos.first == x && pos.second > y) {
				for (int i = pos.second ; i < c; i++) {
					if (vec[x][i] != -1) {
						(*it).second = i;
						found = 1;
						break;
					}
				}
			}

			if (pos.first == x && pos.second < y) {
				for (int i = pos.second ; i >= 0; i--) {
					if (vec[x][i] != -1) {
						(*it).second = i;
						found = 1;
						break;
					}
				}
			}

			if (pos.first > x && pos.second == y) {
				for (int i = pos.first ; i < r; i++) {
					if (vec[i][y] != -1) {
						(*it).first = i;
						found = 1;
						break;
					}
				}
			}

			if (pos.first < x && pos.second == y) {
				for (int i = pos.first ; i >= 0; i--) {
					if (vec[i][y] != -1) {
						(*it).first = i;
						found = 1;
						break;
					}
				}
			}


			if (!found) {
				abc[{x, y}].erase(it);
			} else {
				totalValue += vec[(*it).first][(*it).second];
				count++;
				it++;
			}

		}
	}

	if (totalValue) {
		if (vec[x][y] * count < totalValue) {
			modify[x][y] = -1;
			return true;
		}
	}
	return false;

}


int compete(int test) {
	int c, r;
	int count = 0;
	std::vector<std::vector<int>> vec;
	std::map<std::pair<int, int>, std::vector<std::pair<int,int>>> next;

	std::cin >> r >> c;

	for (int i = 0; i < r; i++) {
		std::vector<int> buffer;
		for (int j = 0; j < c; j++) {
			int value;
			std::cin >> value;
			buffer.push_back(value);
			count+=value;
			if (j != 0) {
				next[{i, j}].push_back({i, j-1});
			}
			if (j != c - 1) {
				next[{i, j}].push_back({i, j+1});
			}
			if (i != 0) {
				next[{i, j}].push_back({i-1, j});
			}
			if (i != r - 1) {
				next[{i, j}].push_back({i+1, j});
			}
		}
		vec.push_back(buffer);
	}

	if (r * c == 1) {
		std::cout << "Case #" << test << ": " << vec[0][0] << std::endl;
		return 0;
	}

	bool continued = true;

	while (continued) {
		std::vector<std::vector<int>> copy = std::vector<std::vector<int>>(vec);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (vec[i][j] != -1) {
					if (!round(copy, vec, r, c, next, i, j)) {
						count += copy[i][j];
					} 
				}
			}
		}
		continued &= check(vec, r, c);
	}

	
	std::cout << "Case #" << test << ": " << count << std::endl;
	return 0;
}


int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		compete(i+1);
	}


}
