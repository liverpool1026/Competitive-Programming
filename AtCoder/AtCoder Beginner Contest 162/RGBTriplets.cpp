#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


long long int validTuplesNew(int N, const std::vector<char>& vec) {
	int G = std::count(vec.begin(), vec.end(), 'G');
	int R = std::count(vec.begin(), vec.end(), 'R');
	int B = std::count(vec.begin(), vec.end(), 'B');

	long long int count = 0;

	for (int i = 1; i < N - 1; i++) {
		if (vec[i-1] == 'G') {
			G--;
		} else if (vec[i-1] == 'R') {
			R--;
		} else {
			B--;
		}
		int g = G;
		int r = R;
		int b = B;
		for (int j = i+1; j < N; j++) {
			if (vec[j-1] == 'G') {
				g--;
			} else if (vec[j-1] == 'R') {
				r--;
			} else {
				b--;
			}
			if (vec[i-1] == vec[j-1]) {
				continue;
			}

			if (vec[i-1] != 'G' && vec[j-1] != 'G') {
				// last one is G
				if (vec[j + j - i - 1] == 'G') {
					count += (g - 1);
				} else {
					count += g;
				}
			}

			if (vec[i-1] != 'R' && vec[j-1] != 'R') {
				// last one is R
				if (vec[j + j - i - 1] == 'R') {
					count += (r - 1);
				} else {
					count += r;
				}
			}

			if (vec[i-1] != 'B' && vec[j-1] != 'B') {
				// last one is B
				if (vec[j + j - i - 1] == 'B') {
					count += (b - 1);
				} else {
					count += b;
				}
			}

		}
	}

	return count;
}


void populate(int N) {
	std::vector<char> vec = std::vector<char>(N);

	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}

	std::cout << validTuplesNew(N, vec) << std::endl;
}




int main() {
	int N;
	std::cin >> N;

	populate(N);
}
