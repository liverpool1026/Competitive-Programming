#include <iostream>
#include <vector>
#include <string>


void populate() {
	int n, a, b;
	char c = 'a';
	std::vector<char> vec;

	std::cin >> n >> a >> b;

	for (int i = 0; i < a; i++) {
		if (i <= a - b) {
			vec.emplace_back(c);
		} else {
			vec.emplace_back(++c);
		}
	}

	for (int i = 0; i < n - a; i++) {
		vec.emplace_back(vec[i]);
	}

	std::cout << std::string(vec.begin(), vec.end()) << std::endl;

}


int main() {
	int T;

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate();
	}


}
