#include <iostream>
#include <string>
#include <unordered_map>


int main() {
	int N;
	std::unordered_map<std::string, int> prizes;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::string str;
		std::cin >> str;
		prizes[str]++;
	}


	std::cout << prizes.size() << std::endl;


}
