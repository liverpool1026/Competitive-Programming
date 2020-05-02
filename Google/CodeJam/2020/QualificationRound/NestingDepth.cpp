#include <iostream>
#include <vector>
#include <string>

std::string handleString(std::string str, int buffer) {

	std::vector<int> value;
	int check = 1;
	int minValue = 10;

	for (char c : str) {
		int n = (int) (c - '0');
		value.push_back(n);
		if (check == 1) {
			check *= n;
		}
		if (n < minValue) {
			minValue = n;
		}
	}


	if (check == 1) {
		if (buffer != 0) {
			std::string a = "(";
			for (int i : value) {
				a = a + std::to_string(i+buffer);
			}
			return a = a + ")";
		}
		return "(" + str + ")";
	}

	std::string resultString = "";

	for (int i = 0; i < minValue; i++) {
		resultString = resultString + "(";
	}

	std::string passDownString = "";
	for (int a : value) {
		if (a - minValue > 0) {
			passDownString = passDownString + std::to_string(a - minValue);
		} else {
			if (passDownString != "") {
				resultString = resultString + handleString(passDownString, buffer + minValue) + std::to_string(a + buffer);
				passDownString = "";
			} else {
				resultString = resultString + std::to_string(a + buffer);
			}
		}
	}

	if (passDownString != "") {
		resultString = resultString + handleString(passDownString, buffer+minValue);
	}

	for (int i = 0; i < minValue; i++) {
		resultString = resultString + ")";
	}

	return resultString;
}


std::string handleStringAll(std::string str) {
	std::string result = "";
	std::string previousStr = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0') {
			if (previousStr != "") {
				result = result + handleString(previousStr, 0) + "0";
				previousStr = "";
			} else {
				result = result + "0";
			}
		} else {
			previousStr += str[i];
		}	
	}

	if (previousStr != "") {
		result = result + handleString(previousStr, 0);
	}

	return result;
}


int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::string str;
		std::cin >> str;
		std::cout << "Case #" << i+1 << ": " << handleStringAll(str) << "\n";
	}
}
	







