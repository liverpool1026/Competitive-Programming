#include <iostream>
#include <string>


int main() {

	std::string str;
	std::cin >> str;

	if (str[2] == str[3] && str[4] == str[5]) {
		std::cout << "Yes";
	} else {
		std::cout << "No";
	}

}
