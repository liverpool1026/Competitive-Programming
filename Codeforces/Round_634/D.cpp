#include <iostream>
#include <string>
#include <vector>


void printMatrix(const std::vector<std::vector<int>>& matrix, int a, int b) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (matrix[i][j] == a) {
				std::cout << b;
			} else {
				std::cout << matrix[i][j];
			}
		}
		std::cout << std::endl;
	}
}


void populate() {
	std::vector<std::vector<int>> matrix;

	for (int i = 0; i < 9; i++) {
		std::string buffer;
		std::cin >> buffer;
		std::vector<int> matrixBuffer;
		for (char c : buffer) {
			matrixBuffer.emplace_back(c - '0');
		}
		matrix.emplace_back(matrixBuffer);

	}

	printMatrix(matrix, 1, 2); 

}




int main() {
	int T;

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate();
	}


}
