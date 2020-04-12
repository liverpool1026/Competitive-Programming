#include <iostream>
#include <vector>
#include <string>


std::string populateStr(std::string maxString, std::string str) {
	if (maxString == "") {
		return "";
	}


	// Find Prefix
	std::vector<char> prefix;
	std::string::iterator maxit = maxString.begin();
	std::string::iterator it = str.begin();

	while (maxit != maxString.end() && it != str.end() && (*maxit != '*' || *it != '*')) {
		if (*maxit != '*' && *it != '*') {
			if (*maxit != *it) {
				return "";
			} else {
				prefix.push_back(*maxit);
				maxit++;
				it++;
			}
		} else if (*maxit != '*') {
			prefix.push_back(*maxit);
			maxit++;
		} else {
			prefix.push_back(*it);
			it++;
		}
	}

	// Find Suffix
	std::vector<char> suffix;
	std::string::reverse_iterator maxrit = maxString.rbegin();
	std::string::reverse_iterator rit = str.rbegin();

	while (maxrit != maxString.rend() && rit != str.rend() && (*maxrit != '*' || *rit != '*')) {
		if (*maxrit != '*' && *rit != '*') {
			if (*maxrit != *rit) {
				return "";
			} else {
				suffix.push_back(*maxrit);
				maxrit++;
				rit++;
			}
		} else if (*maxrit != '*') {
			suffix.push_back(*maxrit);
			maxrit++;
		} else {
			suffix.push_back(*rit);
			rit++;
		}
	}

	prefix.push_back('*');

	// Handle the rest
	while (maxit != maxrit.base() - 1) {
		if (*maxit != '*') {
			prefix.push_back(*maxit);
		}
		maxit++;
	}

	while (it != rit.base() - 1) {
		if (*it != '*') {
			prefix.push_back(*it);
		}
		it++;
	}

	prefix.push_back('*');

	std::vector<char>::reverse_iterator vecrit;

	return std::string(prefix.begin(), prefix.end()) + std::string(suffix.rbegin(), suffix.rend()); 
}


void runTest(int testCase) {
	int n;
	std::cin >> n;
	std::vector<std::string> vec(n);

	for (int i = 0; i < n; i++) {
		std::cin >> vec[i];
	}

	std::string maxString = vec[0];

	for (int i = 1; i < vec.size(); i++) {
		maxString = populateStr(maxString, vec[i]);
	}	


	std::cout << "Case #" << testCase << ": ";

	if (maxString == "") {
		std::cout << "*";
	} else {
		for (char c : maxString) {
			if (c != '*') {
				std::cout << c;
			}
		}
	}

	std::cout << std::endl;
}



int main() {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		runTest(i+1);
	}
}
