#include <iostream>
#include <string>

// My attempt
void increment_b(char* d, int i) {
	if (d[i] == 'a') {
		d[i] = 'b';
	} else if (d[i] == 'b') {
		d[i] = 'a';
		increment_b(d, i-1);
	}
}


int _main() {
	int a;

	std::cin >> a;

	char b[a];

	for (int i = 0; i < a; i++) {
		b[i] = 'a';
	}
	b[a] = '\0';

	std::cout << b; 

	for (int i = 1; i < a; i++) {
		increment_b(b, a-1);

		std::cout << "\n";
		std::cout << b;

	}
	return 0;
}

// Solution

int N;

void dfs(std::string s, char mx) {
	if (s.length() == N) {
		std::cout << s << "\n";
	} else {
		for (char c = 'a'; c <= mx; c++) {
			dfs(s + c, ((c == mx) ? (char) (mx + 1) : mx));
		}
	}
}

int main() {
	std::cin >> N;
	dfs("", 'a');
}
