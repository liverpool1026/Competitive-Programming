#include <iostream>
#include <vector>

void getAllDigits(std::vector<int>& vec, int n) {
	if (n > 9) {
		getAllDigits(vec, n / 10);
	}
	vec.push_back(n % 10);
}

bool isHappy(int n) {
        int result = n;
        while (result != 1) {
		std::vector<int> a;
		getAllDigits(a, result);
    		int count = 0;         
	     	for (int i : a) {
			count += (i * i);
    		}
    		result = count;

		if (result == 4) {
			return false;
		}
	}
	return true;
}



int main() {

	for (int i = 1; i < 10; i++) {
	std::cout << isHappy(i);
	}


}
