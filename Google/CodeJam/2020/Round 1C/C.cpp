#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>


// std::cout << "Case #" << test << ": " << result << std::endl;

bool checkInt(float f) {
	return ceilf(f) == f && floorf(f) == f;
}



void populate(int test) {
	int N, D;
	std::cin >> N >> D;

	std::vector<long long int> vec(N);
	std::unordered_map<long long int, int> cuts;

	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
		cuts[vec[i]]++;
	}

	if (N == 1) {
		std::cout << "Case #" << test << ": " << D - 1 << std::endl;
		return;
	}

	int maxCuts = 0;
	std::vector<long long int> setCut;

	for (auto x: cuts) {
		maxCuts = std::max(maxCuts, x.second);
		setCut.emplace_back(x.first);
	}

	std::sort(setCut.begin(), setCut.end());

	if (maxCuts >= D) {
		std::cout << "Case #" << test << ": 0" << std::endl;
		return;
	}

	int minCut = D - 1;
	for (int i = 0; i < setCut.size(); i++) {
		int required = D - cuts[setCut[i]];
		for (int a = 1; a < 4; a++) {
			int cutCount = 0;
			if (setCut[i] % a && setCut[i] < a) {
				continue;
			}
			int currentRun = setCut[i] / a;
			required = D - cuts[setCut[i]] * a;
			if (required < 0) {
				required = 0;
			}
			if (a != 1) {
				cutCount++;
			}

			for (int j = i + 1; j < setCut.size(); j++) {
				if (!required) {
					break;
				}

				if (!(setCut[j] % currentRun)) {
					long long int maxCanCut = setCut[j] / currentRun;
					for (int k = 0; k < cuts[setCut[j]]; k++) {
						if (required >= maxCanCut) {
							required -=maxCanCut;
							cutCount += (maxCanCut - 1);
						} else {
							cutCount += required;
							required = 0;
						}
					}
				}

			}

			if (required) {
				cutCount += required;
			}

			minCut = std::min(minCut, cutCount);
		}

	}

	std::cout << "Case #" << test << ": " << minCut << std::endl;

}



int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate(i+1);
	}


}
