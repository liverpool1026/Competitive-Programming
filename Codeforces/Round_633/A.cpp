#include <iostream>


void populate() {
	int n;
	std::cin >> n;

	std::cout << n << std::endl;

}


int main() {

	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++) {
		populate();
	}


}
