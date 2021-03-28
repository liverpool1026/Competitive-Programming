#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

int main() {

	int N, M;
	std::cin >> N >> M;

	std::vector<int> height(N+1);

	for (int i = 1; i < N+1; i++) {
		std::cin >> height[i];
	}

	std::vector<std::unordered_set<int>> accessible(N+1);

	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;
		accessible[a].insert(b);
		accessible[b].insert(a);
	}


	int count = 0;
	for (int i = 1; i < N+1; i++) {
		for (int j : accessible[i]) {
			if (height[i] <= height[j]) {
				count--;
				break;
			}
		}
		count++;
	}


	std::cout << count << std::endl;
}

