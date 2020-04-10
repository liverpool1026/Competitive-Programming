#include <iostream>
#include <vector>

int main() {
	int row, column;
	std::cin >> row;
	std::cin >> column;

	std::vector<std::vector<int>> matrix (row, std::vector<int>(column));

	for (int i = 0; i < row; i++) {
		for (int j = 0; i < column; j++) {
			std::cin >> matrix[i][j];
		}
	}

}



