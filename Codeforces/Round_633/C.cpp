#include <iostream>
#include <vector>


void populate() {
	int n;
	int count = 0;
	long long int currentValue = 1;
	std::cin >> n;
	std::vector<long long int> vec(n);
	std::vector<long long int> addValue;

	for (int i = 0; i < n; i++) {
		std::cin >> vec[i];
	}

	for (int i = 1; i < vec.size(); i++) {
		if (vec[i-1] > vec[i]) {
			for (int j : addValue) {
				vec[i]+=j;
				if (vec[i] >= vec[i-1]) {
					break;
				}
			}
			while (vec[i-1] > vec[i]) {
				vec[i]+=currentValue;
				addValue.emplace_back(currentValue);
				currentValue *= 2;
				count++;
			}
			if (vec[i] - vec[i-1]) {
				int differ = vec[i] - vec[i-1];
				int copy = differ;

				for (int i = 0; i < addValue.size() - 1; i++) {
					if (differ == addValue[i]) {
						vec[i] == vec[i-1];
						break;
					} else if (copy - addValue[i] > 0) {
						copy -= addValue[i];
					}
				}

				if (vec[i] != vec[i-1]) {
					vec[i] = vec[i-1] + copy;
				}
			}

		}
	}

	std::cout << count << std::endl;



}


int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate();
	}
}
