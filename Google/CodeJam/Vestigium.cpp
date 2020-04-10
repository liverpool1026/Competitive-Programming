#include <iostream>
#include <map>


int calculateTrace(const std::map<std::pair<int, int>, int>& matrix, int N) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		count += matrix.at({i, i});
	}

	return count;
}

void processMatrix(int caseIndex, int N) {
	std::map<std::pair<int, int>, int> matrix;
	std::map<std::pair<int, int>, bool> rowMatrix; // <row, value>
	std::map<std::pair<int, int>, bool> columnMatrix; // <col, value>
	std::map<int, int> columnFlag; 
	std::map<int, int> rowFlag; 


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int value;
			std::cin >> value;
			matrix.insert({{i, j}, value});
			if (rowFlag[i] == 0 && rowMatrix.find({i, value}) != rowMatrix.end()) {
				//value exist in that row
				rowFlag[i] = 1;
			} else {
				rowMatrix.insert({{i, value}, true});
			}
			if (columnFlag[j] == 0 && columnMatrix.find({j, value}) != columnMatrix.end()) {
				//value exist in that column
				columnFlag[j] = 1;
			} else {
				columnMatrix.insert({{j, value}, true});
			}

		}
	}

	int rowCount = 0;
	int colCount = 0;

	for (auto const& row : rowFlag) {
		rowCount += row.second;
	}

	for (auto const& col : columnFlag) {
		colCount += col.second;
	}

	std::cout << "Case #" << caseIndex << ": " << calculateTrace(matrix, N) << " " << rowCount << " " << colCount << "\n"; 
}


int main() {
	int testCases;
	std::cin >> testCases;


	for (int i = 0; i < testCases; i++) {
		int N;
		std::cin >> N;
		processMatrix(i+1, N);
	}
}

