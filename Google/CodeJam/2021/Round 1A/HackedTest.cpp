#include <vector>
#include <string>
#include <iostream>


void hack(int test) {

	int i, j;
	std::cin >> i >> j;
	int score;
	std::vector<char> result(j);

	for (int a = 0; a < j; a++) {
		std::cin >> result[a];
	}

	std::cin >> score;

	for (int x = 0; x < i - 1; x++) {
		int c;
		std::vector<char> results(j);
		for (int a = 0; a < j; a++) {
			std::cin >> results[a];
		}
		std::cin >> c;

		if (c > score) {
			score = c;
			result = results;
		} else if (j - c > score) {
			score = j -c;
			for (int a = 0; a < j; a++) {
				result[a] = results[a] == 'F' ? 'T' : 'F';
			}
		}
	}

	std::cout << "Case #" << test << ": ";
	for (char c : result) {
		std::cout << c;
	}
	
	std::cout << " " << score << "/1" << std::endl;
}



int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		hack(i+1);
	}


}
