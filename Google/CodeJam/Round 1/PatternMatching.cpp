#include <iostream>
#include <vector>
#include <string>
#include <map>


std::string checkMaxMatchedArray(std::string current, std::string next) {
	std::vector<char> result;

	if (current == "") {
		return next;
	}

	std::string::iterator cit = current.begin();
	std::string::iterator nit = next.begin();
	if (*cit != '*' && *nit != '*') {
		while (cit != current.end() && nit != next.end() && *cit != '*' && *nit != '*') {
			if (*cit != *nit) {
				return "";
			} else {
				result.push_back(*cit);
			}
			cit++;
			nit++;
		}
	}

	std::string::reverse_iterator crit = current.rbegin();
	std::string::reverse_iterator nrit = next.rbegin();
	std::vector<char> reverseResult;

	if (*crit != '*' && *nrit != '*') {
		while (crit != current.rend() && nrit != next.rend() && *crit != '*' && *nrit != '*') {
			if (*crit != *nrit) {
				return "";
			} else {
				reverseResult.push_back(*crit);
			}
			crit++;
			nrit++;
		}
	}

	if (*cit == '*' && *nit == '*') {
		result.push_back('*');
	}

	while (cit != current.end() && *cit != '*') {
		result.push_back(*cit);
		cit++;
	}
	while (nit != next.end() && *nit != '*') {
		result.push_back(*nit);
		nit++;
	}

	if (*crit == '*' && *nrit == '*') {
		reverseResult.push_back('*');
	}

	while (crit != current.rend() && *crit != '*') {
		reverseResult.push_back(*crit);
		crit++;
	}

	while (nrit != current.rend() && *nrit != '*') {
		reverseResult.push_back(*nrit);
		nrit++;
	}

	std::vector<char>::reverse_iterator rit;

	for (rit = reverseResult.rbegin(); rit != reverseResult.rend(); rit++) {
		if (rit == reverseResult.rbegin()) {
			result.push_back('*');
		}
		result.push_back(*rit);
	}

	return std::string(result.begin(), result.end());

}





int findPattern(int t) {
	int n;
	std::string maxMatchedArray = "";
	int flag = 1;

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		if (flag) {
			maxMatchedArray = checkMaxMatchedArray(maxMatchedArray, str);

			if (maxMatchedArray == "") {
				flag = 0;
			}
		}
	}


	if (!flag) {
		std::cout << "Case #" << t << ": *" << std::endl;
		return 0;
	}

	std::vector<char> result;

	for (char c : maxMatchedArray) {
		if (c != '*') {
			result.push_back(c);
		}
	}

	std::cout << "Case #" << t << ": " << std::string(result.begin(), result.end()) << std::endl;
	return 0;
}



int main() {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; i++) {
		findPattern(i+1);
	}
}
