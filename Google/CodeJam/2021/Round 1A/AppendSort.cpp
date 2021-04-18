#include <vector>
#include <string>
#include <iostream>


int operations(std::vector<unsigned long long>& vec, int x) {
	unsigned long long a = vec[x];
	unsigned long long b = vec[x+1];

	if (b > a) {
		return 0;
	} else if (b == a) {
		vec[x+1] = b * 10;
		return 1;
	} else {
		std::string str_a = std::to_string(a);
		std::string str_b = std::to_string(b);


		int a_length = (int) str_a.length();
		int b_length = (int) str_b.length();
		int ops;

		if (str_b[0] > str_a[0]) {
			ops = a_length - b_length;
		} else if (b_length == a_length || str_b[0] < str_a[0]) {
			ops = a_length - b_length + 1;
		} else {
			int c = 0;
			for (int i = 0; i < b_length; i++) {
			       if (str_b[i] > str_a[i]) {
				       c = 1;
			       } else if (str_b[i] < str_a[i]) {
				       c = 2;
			       }

			       if (c) {
				       break;
			       }
			}

			if (c == 1) {
				ops = a_length - b_length;
			} else if (c == 2) {
				ops = a_length - b_length + 1;
			} else {
				int flag = 0;
				for (int i = b_length; i < a_length; i++) {
					if (str_a[i] != '9') {
						flag = 1;
						break;
					}	

				}

				if (flag) {
					vec[x+1] = a+1;
					return a_length - b_length;

				} else {
					ops = a_length - b_length + 1;
				}

			}

		}

		for (int i = 0; i < ops; i++) {
			vec[x+1]*=10;
		}
		return ops;
	}
}


void append(int test) {

	int i;
	int ops = 0;
	std::cin >> i;
	std::vector<unsigned long long> vec(i);

	for (int x = 0; x < i; x++) {
		std::cin >> vec[x];
	}


	for (int x = 0; x < i-1; x++) {
		ops += operations(vec, x);
	}

	std::cout << "Case #" << test << ": "<< ops << std::endl;
}



int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		append(i+1);
	}


}
