#include <iostream>
#include <string>



int main() {
	int N;
	bool contains = false;
	std::cin >> N;

	std::string str = std::to_string(N);

	for (char c : str) {
		if (c == '7') {
			contains = true;
		}
	}

	if (contains) {
		std::cout << "Yes" << std::endl;
	} else {
		std::cout << "No" << std::endl;
	}
}



