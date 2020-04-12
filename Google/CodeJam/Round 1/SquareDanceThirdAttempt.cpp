#include <iostream>
#include <vector>
#include <map>

using namespace std;

void printArray(const vector<vector<int>>& matrix, int r, int c) {
	cout << "Array: \n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << matrix[i][j] << " ";
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


void postRoundProcessing(vector<vector<int>>& matrix, const vector<pair<int, int>>& elimated, map<pair<int, int>, pair<int, int>>& up, map<pair<int, int>, pair<int, int>>& down, map<pair<int, int>, pair<int, int>>& right, map<pair<int, int>, pair<int, int>>& left) {

	for (pair<int, int> par : elimated) {

		int i = par.first;
		int j = par.second;
		matrix[i][j] = -1;

		// Current next right will be my left's new right and vice versa
		right[{i, left[{i, j}].second}] = right[{i, j}];
		left[{i, right[{i, j}].second}] = left[{i, j}];

		up[{down[{i, j}].first, j}] = up[{i, j}];
		down[{up[{i, j}].first, j}] = down[{i, j}];
	}
}



bool checkFinished(const vector<vector<int>>& matrix, int r, int c, const map<pair<int, int>, pair<int, int>>& up, const map<pair<int, int>, pair<int, int>>& down, const map<pair<int, int>, pair<int, int>>& right, const map<pair<int, int>, pair<int, int>>& left) {
	bool continued = true;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (continued && matrix[i][j] != -1) {
				bool b = false;
				if (up.at({i, j}).first != -1) {
					b = true;
				}
				if (right.at({i, j}).first != -1) {
					b = true;
				}
				if (down.at({i, j}).first != -1) {
					b = true;
				}
				if (left.at({i, j}).first != -1) {
					b = true;
				}

				continued &= b;
			}
		}
	}

	return continued;


}

int playRound(vector<vector<int>>& matrix, vector<pair<int, int>>& elminated, int r, int c, map<pair<int, int>, pair<int, int>>& up, map<pair<int, int>, pair<int, int>>& down, map<pair<int, int>, pair<int, int>>& right, map<pair<int, int>, pair<int, int>>& left) {
	int interestLevel = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int count = 0;
			int value = 0;

			if (matrix[i][j] != -1) {

				if (up[{i, j}].first != -1) {
					count++;
					value+=matrix[up[{i, j}].first][up[{i, j}].second];
				}

				if (down[{i, j}].first != -1) {
					count++;
					value+=matrix[down[{i, j}].first][down[{i, j}].second];
				}

				if (left[{i, j}].first != -1) {
					count++;
					value+=matrix[left[{i, j}].first][left[{i, j}].second];
				}

				if (right[{i, j}].first != -1) {
					count++;
					value+=matrix[right[{i, j}].first][right[{i, j}].second];
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
	map<pair<int, int>, pair<int, int>> compassNeighbourUp;
	map<pair<int, int>, pair<int, int>> compassNeighbourDown;
	map<pair<int, int>, pair<int, int>> compassNeighbourRight;
	map<pair<int, int>, pair<int, int>> compassNeighbourLeft;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
			interestLevel+=matrix[i][j];

			if (i != 0) {
				compassNeighbourUp[{i, j}] = {i-1, j};
			} else {
				compassNeighbourUp[{i, j}] = {-1, -1};
			}

			if (j != 0) {
				compassNeighbourLeft[{i, j}] = {i, j-1};
			} else {
				compassNeighbourLeft[{i, j}] = {-1, -1};
			}

			if (i != r-1) {
				compassNeighbourDown[{i, j}] = {i+1, j};
			} else {
				compassNeighbourDown[{i, j}] = {-1, -1};
			}

			if (j != c-1) {
				compassNeighbourRight[{i, j}] = {i, j+1};
			} else {
				compassNeighbourRight[{i, j}] = {-1, -1};
			}
		}
	}


	if (r == 1 && c == 1) {
		continued = false;
	}

	//printArray(matrix, r, c);
	while (continued) {
		vector<pair<int, int>> elimatedList;
		// Play round
		interestLevel+=playRound(matrix, elimatedList, r, c, compassNeighbourUp, compassNeighbourDown, compassNeighbourRight, compassNeighbourLeft);
		// Deal with elimiated player
		postRoundProcessing(matrix, elimatedList, compassNeighbourUp, compassNeighbourDown, compassNeighbourRight, compassNeighbourLeft);
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
