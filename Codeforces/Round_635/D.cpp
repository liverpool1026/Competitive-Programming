#include <iostream>
#include <algorithm>
#include <vector>

long long int getMinValue(const std::vector<std::pair<long long int, char>>& superList, int index, char findOne, char findTwo) {
	long long int currentValue = superList[index].first;
	std::pair<long long int, long long int> one = {0, 0};
	std::pair<long long int, long long int> two = {0, 0};

	int findFlag = 0;
	int findFlagTwp = 0;


	for (int i = index; i >= 0; i--) {
		if (findFlag && findFlagTwp) {
			break;
		}

		if (!findFlag && superList[i].second == findOne) {
			one.first = superList[i].first;
			findFlag = 1;
		}

		if (!findFlagTwp && superList[i].second == findTwo) {
			two.first = superList[i].first;
			findFlagTwp = 1;
		}
	}

	findFlag = 0;
	findFlagTwp = 0;

	for (int i = index; i < superList.size(); i++) {
		if (findFlag && findFlagTwp) {
			break;
		}

		if (!findFlag && superList[i].second == findOne) {
			one.second = superList[i].first;
			findFlag = 1;
		}

		if (!findFlagTwp && superList[i].second == findTwo) {
			two.second = superList[i].first;
			findFlagTwp = 1;
		}
	}

	long long int minValue = 0;

	if (one.first) {
		if (two.first) {
			minValue = (one.first - two.first) * (one.first - two.first) + (one.first - currentValue) * (one.first - currentValue) + (two.first - currentValue) * (two.first - currentValue);
		}

		if (two.second) {
			if (minValue) {
				minValue = std::min(minValue, (one.first - two.second) * (one.first - two.second) + (one.first - currentValue) * (one.first - currentValue) + (two.second - currentValue) * (two.second - currentValue));
			} else {
				minValue = (one.first - two.second) * (one.first - two.second) + (one.first - currentValue) * (one.first - currentValue) + (two.second - currentValue) * (two.second - currentValue);
			}
		}
	}

	if (one.second) {
		if (two.first) {

			if (minValue) {
				minValue = std::min(minValue, (one.second - two.first) * (one.second - two.first) + (one.second - currentValue) * (one.second - currentValue) + (two.first - currentValue) * (two.first - currentValue));
			} else {
				minValue = (one.second - two.first) * (one.second - two.first) + (one.second - currentValue) * (one.second - currentValue) + (two.first - currentValue) * (two.first - currentValue);
			}
		}


		if (two.second) {
			if (minValue) {
				minValue = std::min(minValue, (one.second - two.second) * (one.second - two.second) + (one.second - currentValue) * (one.second - currentValue) + (two.second - currentValue) * (two.second - currentValue));
			} else {
				minValue = (one.second - two.second) * (one.second - two.second) + (one.second - currentValue) * (one.second - currentValue) + (two.second - currentValue) * (two.second - currentValue);
			}


		}
	}


	return minValue;
}	


void populate() {
	int r, g, b;

	std::cin >> r >> g >> b;
	std::vector<long long int> red(r);
	std::vector<long long int> green(g);
	std::vector<long long int> blue(b);
	std::vector<std::pair<long long int, char>> superList;

	for (int i = 0; i < r; i++) {
		std::cin >> red[i];
		superList.emplace_back(red[i], 'r');
	}
	
	for (int i = 0; i < g; i++) {
		std::cin >> green[i];
		superList.emplace_back(green[i], 'g');
	}

	for (int i = 0; i < b; i++) {
		std::cin >> blue[i];
		superList.emplace_back(blue[i], 'b');
	}


	long long int superMin = 0;

	std::sort(superList.begin(), superList.end());


	for (int i = 0; i < superList.size(); i++) {
		if (superList[i].second == 'r') {
			long long int buffer = getMinValue(superList, i, 'b', 'g');
			if (buffer) {

				if (superMin) {
					superMin = std::min(superMin, buffer);
				} else {
					superMin = buffer;
				}
			}
		}
	}

	for (int i = 0; i < superList.size(); i++) {
		if (superList[i].second == 'g') {
			long long int buffer = getMinValue(superList, i, 'b', 'r');
			if (buffer) {

				if (superMin) {
					superMin = std::min(superMin, buffer);
				} else {
					superMin = buffer;
				}
			}
		}
	}

	for (int i = 0; i < superList.size(); i++) {
		if (superList[i].second == 'b') {
			long long int buffer = getMinValue(superList, i, 'r', 'g');
			if (buffer) {

				if (superMin) {
					superMin = std::min(superMin, buffer);
				} else {
					superMin = buffer;
				}
			}
		}
	}

	std::cout << superMin << std::endl;

}




int main() {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate();
	}
}
