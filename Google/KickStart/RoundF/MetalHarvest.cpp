#include <vector>
#include <iostream>
#include <algorithm>


void populate(int testCase) {

	int N, K;
	std::cin >> N >> K;

	std::vector<std::pair<int, int>> vIntervals;

	for (int i = 0; i < N; i++) {
		int a, b; 
		std::cin >> a >> b;
		vIntervals.push_back({a, b - 1});
	}


	std::sort(vIntervals.begin(), vIntervals.end());

	int count = 0;
	int robotTillTime = -1;

	for (std::pair<int, int> par : vIntervals) {
		if (robotTillTime < par.first) {
			count++;
			robotTillTime = par.first + K - 1;
		}

		if (robotTillTime < par.second) {
			int durationYetDone = par.second - robotTillTime;
			if (durationYetDone < K) {
				count++;
				robotTillTime += K;
			} else if (durationYetDone % K) {
				count += durationYetDone / K + 1;
				robotTillTime += ((durationYetDone / K + 1) * K);
			} else {
				count += durationYetDone / K;
				robotTillTime = par.second;
			}
		}
	}

	std::cout << "Case #" << testCase << ": " << count << std::endl;
}


int main() {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate(i+1);
	}

}
