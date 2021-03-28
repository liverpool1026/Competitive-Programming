#include <vector>
#include <iostream>
#include <algorithm>


void populate(int testCase) {

	int N, X;
	std::cin >> N >> X;

	std::vector<std::pair<int, int>> vCountIndex;

	// O(n)
	for (int i = 0; i < N; i++) {
		int count; 
		std::cin >> count;
		vCountIndex.push_back({count % X ? count / X + 1 : count / X, i});
	}


	std::sort(vCountIndex.begin(), vCountIndex.end());

	std::cout << "Case #" << testCase << ":";
	for (std::pair<int, int> par : vCountIndex) {
		std::cout << " " << par.second + 1;
	}

	std::cout << std::endl;



}


int main() {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate(i+1);
	}

}
