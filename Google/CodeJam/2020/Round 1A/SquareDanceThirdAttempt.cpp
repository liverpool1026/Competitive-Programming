#include <iostream>
#include <vector>
#include <map>

using namespace std;

void printArray(const vector<vector<pair<int, int>>>& matrix, int r, int c) {
	cout << "Array: \n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << matrix[i][j].first << ", " << matrix[i][j].second << " ";
		}
		cout << endl;
	}
}


void printMap(const map<pair<int, int>, pair<int, int>>& mapObj, int r, int c, string header) {
	cout << header << ": \n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "(i, j): (" << i << ", " << j << "): " << mapObj.at({i, j}).first << ", " << mapObj.at({i, j}).second << "\n";
		}
	}
}


void postRoundProcessing(vector<vector<int>>& matrix, const vector<pair<int, int>>& elimated, vector<vector<pair<int, int>>>& up, vector<vector<pair<int, int>>>& down, vector<vector<pair<int, int>>>& right, vector<vector<pair<int, int>>>& left, int r, int c) {

	for (pair<int, int> par : elimated) {

		int i = par.first;
		int j = par.second;
		matrix[i][j] = -1;

		std::cout << i << ", " << j << "\n";
		// Current next right will be my left's new right and vice versa
		if (i) {
			if (down[i][j].first != -1) {
				up[down[i][j].first][j] = up[i][j];
			}
		}

		if (j) {
			if (right[i][j].second != -1) {
				left[i][right[i][j].second] = left[i][j];
			}
		}

		if (i != r - 1) {
			if (up[i][j].first != -1) {
				down[up[i][j].first][j] = down[i][j];
			}
		}

		if (j != c - 1) {
			if (right[i][j].second != -1) {
				right[i][left[i][j].second] = right[i][j];
			}
		}

	}
}



bool checkFinished(const vector<vector<int>>& matrix, int r, int c, const vector<vector<pair<int, int>>>& up, const vector<vector<pair<int, int>>>& down, const vector<vector<pair<int, int>>>& right, const vector<vector<pair<int, int>>>& left) {
	bool continued = true;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (continued && matrix[i][j] != -1) {
				bool b = false;
				if (up[i][j].first != -1) {
					b = true;
				}
				if (right[i][j].first != -1) {
					b = true;
				}
				if (down[i][j].first != -1) {
					b = true;
				}
				if (left[i][j].first != -1) {
					b = true;
				}

				continued &= b;
			}
		}
	}

	return continued;


}

int playRound(vector<vector<int>>& matrix, vector<pair<int, int>>& elminated, int r, int c, vector<vector<pair<int, int>>>& up, vector<vector<pair<int, int>>>& down, vector<vector<pair<int, int>>>& right, vector<vector<pair<int, int>>>& left) {
	int interestLevel = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int count = 0;
			int value = 0;

			if (matrix[i][j] != -1) {

				if (up[i][j].first != -1) {
					count++;
					value+=matrix[up[i][j].first][up[i][j].second];
				}

				if (down[i][j].first != -1) {
					count++;
					value+=matrix[down[i][j].first][down[i][j].second];
				}

				if (left[i][j].first != -1) {
					count++;
					value+=matrix[left[i][j].first][left[i][j].second];
				}

				if (right[i][j].first != -1) {
					count++;
					value+=matrix[right[i][j].first][right[i][j].second];
				}

				if (matrix[i][j] * count < value) {
					//Eliminated
					elminated.emplace_back(i, j);
				} else {
					interestLevel += matrix[i][j];
				}
			}

		}
	}
	return interestLevel;
}




int compete(int test) {
	int c, r;
	bool continued = true;
	int interestLevel = 0;
	
	cin >> r >> c;
	vector<vector<int>> matrix(r, vector<int>(c));

	vector<vector<pair<int, int>>> compassNeighbourUp(r, vector<pair<int, int>>(c));
	vector<vector<pair<int, int>>> compassNeighbourDown(r, vector<pair<int, int>>(c));
	vector<vector<pair<int, int>>> compassNeighbourLeft(r, vector<pair<int, int>>(c));
	vector<vector<pair<int, int>>> compassNeighbourRight(r, vector<pair<int, int>>(c));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
			interestLevel+=matrix[i][j];

			if (i != 0) {
				compassNeighbourUp[i][j] = {i-1, j};
			} else {
				compassNeighbourUp[i][j] = {-1, -1};
			}

			if (j != 0) {
				compassNeighbourLeft[i][j] = {i, j-1};
			} else {
				compassNeighbourLeft[i][j] = {-1, -1};
			}

			if (i != r-1) {
				compassNeighbourDown[i][j] = {i+1, j};
			} else {
				compassNeighbourDown[i][j] = {-1, -1};
			}

			if (j != c-1) {
				compassNeighbourRight[i][j] = {i, j+1};
			} else {
				compassNeighbourRight[i][j] = {-1, -1};
			}
		}
	}

	//printArray(compassNeighbourUp, r, c);
	//printArray(compassNeighbourDown, r, c);
	//printArray(compassNeighbourLeft, r, c);
	//printArray(compassNeighbourRight, r, c);

	if (r == 1 && c == 1) {
		continued = false;
	}

	//printArray(matrix, r, c);
	while (continued) {
		vector<pair<int, int>> elimatedList;
		// Play round
		interestLevel+=playRound(matrix, elimatedList, r, c, compassNeighbourUp, compassNeighbourDown, compassNeighbourRight, compassNeighbourLeft);
		// Deal with elimiated player
		postRoundProcessing(matrix, elimatedList, compassNeighbourUp, compassNeighbourDown, compassNeighbourRight, compassNeighbourLeft, r, c);
		//printArray(matrix, r, c);
		// Check if finished
		//printMap(compassNeighbourUp, r, c, "UP");
		//printMap(compassNeighbourDown, r, c, "Down");
		//printMap(compassNeighbourRight, r, c, "Right");
		//printMap(compassNeighbourLeft, r, c, "Left");
		continued = checkFinished(matrix, r, c, compassNeighbourUp, compassNeighbourDown, compassNeighbourRight, compassNeighbourLeft);
	}
	

	cout << "Case #" << test << ": " << interestLevel << endl;
	return 0;
}


int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		compete(i+1);
	}


}
