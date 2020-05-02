#include <iostream>
#include <vector>
#include <map>

void populateLatinSquare(int testIndex, int N, int K) {

}


void calculateTrace(int value, int availableCount, int range, std::vector<int>& a) {
	if (range == availableCount + 1 || range == availableCount - 1) {
		std::cout << "Case #" << value << ": IMPOSSIBLE" << "\n";
	} else {
		int** array = new int*[range];
		for (int i = 0; i < range; i++) {
			array[i] = new int[range];
		}
		if (range == availableCount || range == availableCount * availableCount) {
			int b = 1;
			if (range != availableCount) {
				b = availableCount;
			}

			for (int i = 0; i < range; i++) {
				for (int j =0; j < range; j++) {
					if (i == j) {
						array[i][j] = b;
					} else {
						if (j+i < range) 
						array[i][j] = j + i;
					}
				}
			}

			



}


	


int main() {

	std::vector<int> a;
	calculateTrace(25, 5, 5, a);
	for (int i : a) {
		std::cout << i << "\n";
	}

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int N, K;
		std::cin >> N >> K;
		populateLatinSquare(i+1, N, K);
	}

}
