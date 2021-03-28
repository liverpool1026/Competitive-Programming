#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <algorithm>



void populate(int test) {

	int U;
	std::cin >> U;

	std::vector<std::unordered_set<char>> vec(10);
	std::unordered_map<char, bool> mapping;
	std::unordered_set<char> allChar;
	std::unordered_map<char, int> allMapping;

	for (int i = 0; i < 1e4; i++) {
		long long int I;
		std::cin >> I;
		std::string str;
		std::cin >> str;
		if (I == -1) {
			allMapping[str[0]]++;
		} else if (I < 10) {
			vec[I-1].insert(str[0]);
		} else {
			if ((int) std::log10(I) + 1 == (int)str.length()) {
				vec[(int) (std::to_string(I)[0] - '0') - 1].insert(str[0]);
			}
		}
		mapping[str[0]] = true;
		for (char c: str) {
			allChar.insert(c);
		}
	}

	std::vector<char> result;
	std::vector<std::pair<int, char>> newVec;

	for (auto x : allMapping) {
		newVec.emplace_back(x.second, x.first);
	}

	for (char c: allChar) {
		if (mapping.find(c) == mapping.end()) {
			result.emplace_back(c);
			break;
		}
	}

	if (newVec.size()) {

		std::sort(newVec.rbegin(), newVec.rend());
		for (std::pair<int, char> par : newVec) {
			result.emplace_back(par.second);
		}
	} else {

		for (int i = 0; i < 10; i++) {
			for (const char c : vec[i]) {
				if (std::find(result.begin(), result.end(), c) == result.end()) {
					result.emplace_back(c);
					break;
				}
					
			}
		}	
	}

	std::cout << "Case #" << test << ": " << std::string(result.begin(), result.end()) << std::endl;

}



int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate(i+1);
	}


}
