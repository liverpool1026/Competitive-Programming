#include <iostream>
#include <vector>
#include <map>
#include <string>


// std::cout << "Case #" << test << ": " << result << std::endl;


int getResponse() {
	std::string response;
	std::cin >> response;

	if (response == "CENTER") {
		return 0;
	} else if (response == "HIT") {
		return 1;
	} else if (response == "WRONG") {
		exit();
	} else {
		return 2;
	}
}



void populate(int test) {
	std::cout << "0 0" << std::endl;

	while (true) {
		int response = getResponse();
		if (!response) {
			break;
		} else {


		}



}



int main() {
	int T, A, B;
	std::cin >> T >> A >> B;

	for (int i = 0; i < T; i++) {
		populate(i+1, A, B);
	}


}
