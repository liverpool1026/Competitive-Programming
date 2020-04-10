#include <iostream>
#include <string>


int main() {

	std::string s;
	std::cin >> s;

	int l = s.length();

	for (int i = 0; i < (l - 1) / 2; i++) {
		if (s[i] != s[(l - 1) / 2 - 1 -i]) {
			std::cout << "No";
			return 0;
		}

		if (s[i] != s[l - i - 1]) {
			std::cout << "No";
			return 0;
		}
	}

	std::cout << "Yes";
	return 0;

}
