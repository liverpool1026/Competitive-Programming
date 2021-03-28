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
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cin >> plot[{i, j}];
		}
	}

	if (plot[{0, 0}] == 1) {
		dpA[0][0] = 1;
		dpB[0][0] = 1;
		dpC[0][0] = 1;
		dpD[0][0] = 1;
	}

	if (plot[{R-1, C-1}] == 1) {
		dpA[R-1][C-1] = 1;
		dpB[R-1][C-1] = 1;
		dpC[R-1][C-1] = 1;
		dpD[R-1][C-1] = 1;
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (plot[{i, j}] == 1) {
				dpA[i][j] = 1;
				dpB[i][j] = 1;

				if (i != 0) {
					if (dpA[i-1][j] != 0) {
						dpA[i][j] = dpA[i-1][j] + 1;
					}
				}

				if (j != 0) {
					if (dpB[i][j-1] != 0) {
						dpB[i][j] = dpB[i][j-1] + 1;
					}
				}
			}
		}
	}

	for (int i = R - 1; i >= 0; i--) {
		for (int j = C - 1; j >= 0; j--) {
			if (plot[{i, j}] == 1) {
				dpC[i][j] = 1;
				dpD[i][j] = 1;
				if (i != R - 1) {
					if (dpC[i+1][j] != 0) {
						dpC[i][j] = dpC[i+1][j] + 1;
					}
				}

				if (j != C - 1) {
					if (dpD[i][j+1] != 0) {
						dpD[i][j] = dpD[i][j+1] + 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (dpA[i][j] == 1) {
				dpA[i][j] = 0;
			}
			if (dpB[i][j] == 1) {
				dpB[i][j] = 0;
			}
			if (dpC[i][j] == 1) {
				dpC[i][j] = 0;
			}
			if (dpD[i][j] == 1) {
				dpD[i][j] = 0;
			}
		}
	}

	int count = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::vector<int> upDown{dpA[i][j], dpC[i][j]};
			std::vector<int> leftRight{dpB[i][j], dpD[i][j]};

			for (int a : upDown) {
				for (int b : leftRight) {
					if (a && b) {
						int big, small;
						if (a > b) {
							big = a;
							small = b;
						} else {
							big = b;
							small = a;
						}

//						std::cout << "(" << i << ", " << j << "): " << big << ", " << small << "\n";

						while (small >= 2) {
							if (small * 2 <= big) {
								if (a == b) {
									count++;
								}
								count++;
							}
							small--;
						}
					}
				}
			}


		}
	}

/*	std::cout << count << "\n";

	std::cout << "\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cout << dpA[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cout << dpB[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cout << dpC[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cout << dpD[i][j] << " ";
		}
		std::cout << "\n";
	}
*/

		std::cout << "Case #" << testCase << ": " << count << std::endl;







}


int main() {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate(i+1);
	}

}
