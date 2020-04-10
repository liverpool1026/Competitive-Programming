#include <iostream>
#include <vector>
#include <map>


void populate(int count) {
	std::vector<long long int> array;
	std::vector<int> single;
	long long int total = 0;
	long long int goodArray = 0;

	for (int i = 0; i < count; i++) {
		int b;
		std::cin >> b;
		total+=b;
		array.push_back(total);
		single.push_back(b);
	}

	int previousIndex = 0;
	std::map<long long int, int> entry;
	for (int i = 0; i < count; i++) {
		int flag = 1;

		for (int j = previousIndex; j < count; j++) {
			if (!array[j] || entry.find(array[j]) != entry.end()) {
				int value = std::max(0, j - i);
				goodArray = goodArray + value;
				if (j == previousIndex) {
					if (single[j]) {
						goodArray++;
					}
					previousIndex++;
				} else {
					previousIndex = j;
				}
				flag = 0;
				break;
			} else {
				entry[array[j]] = 1;
			}
		}

		if (flag) {
			int value = std::max(0, count - i);
			goodArray = goodArray + value;
			for (int k = i+1; k < count; k++) {
				value = std::max(0, count - k);
				goodArray = goodArray + value;
			}
			break;
		} 

		entry.erase(array[i]);

	}

	std::cout << goodArray << std::endl;

}




int main() {
	int counts;

	std::cin >> counts;

	populate(counts);

}
