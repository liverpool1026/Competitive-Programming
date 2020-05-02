#include <iostream>
#include <vector>
#include <map>
#include <string>




void populate(int test) {
	int X, Y;
	std::cin >> X >> Y;

	std::string route;
	std::cin >> route;

	std::vector<std::pair<int, int>> vec = {{X, Y}};

	for (int i = 0; i < route.length(); i++) {
		char c = route[i];
		switch (c) {
			case 'N':
				Y++;
				break;
			case 'S':
				Y--;
				break;
			case 'W':
				X--;
				break;
			case 'E':
				X++;
				break;
			default:
				break;
		}
		if (std::abs(X) + std::abs(Y) <= i+1) {
			std::cout << "Case #" << test << ": " << i + 1 << std::endl;
			return;
		}

	}

	std::cout << "Case #" << test << ": IMPOSSIBLE" << std::endl;

}



int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate(i+1);
	}


}
