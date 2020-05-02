#include <iostream>

void test(int a) {
	int** array = new int*[a];

	for (int i=0; i < a; i++) {
		array[i] = new int[a];
	}

	for (int i =0; i < a; i++) {
		std::cout << array[i][i] << "\n";
	}

}


int main() {
	test(5);
}

