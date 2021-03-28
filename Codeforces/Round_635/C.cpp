#include <iostream>
#include <algorithm>
#include <vector>


std::vector<int> shortestPath(const std::vector<std::vector<int>>& routes, int currentLocation, std::vector<int> passed) {
	std::vector<int> passing = {currentLocation};

	if (routes[currentLocation][0]) {
		return passing;
	} else {
		for (int i = 0; i < routes[currentLocation].size(); i++) {
			if (routes[currentLocation][i]) {
				if (std::find(passed.begin(), passed.end(), i) == passed.end()) {
					shortestPathDistance = shortestPath(routes, i, passed);
				}
			}

		}
	}
}



void populate() {
	int n, k;
	std::cin >> n >> k;

	int start = k;
	
	std::vector<std::vector<int>> routes(n, std::vector<int>(n));
	std::vector<std::pair<int, std::vector<int>>> travelPassCount(n);

	for (int i = 0; i < n-1; i++) {
		int a, b;
		std::cin >> a >> b;
		routes[a-1][b-1] = 1;
		routes[b-1][a-1] = 1;
	}

	for (int i = 2; i < n + 1; i++) {
		std::vector<int> passedCity;
		int currentLocation = i - 1;
		while(currentLocation != 0) {
			passedCity.emplace_back(currentLocation);
			for (int j = 0; j < n; j++) {
				if (routes[currentLocation][j]) {
					if (std::find(passedCity.begin(), passedCity.end(), j) == passedCity.end()) {
					currentLocation = j;
					break;
					}
				}
			}
		}
		travelPassCount[i-1] = {passedCity.size(), passedCity};
	}

	std::vector<std::vector<int>> cityCount(n);

	for (int i = 1; i < n; i++) {
		cityCount[travelPassCount[i].first].emplace_back(i);
	}

	std::vector<int> industryCity;

	for (int i = n - 1; i > 0; i--) {
		if (cityCount[i].size() && k >= cityCount[i].size()) {
			k -= cityCount[i].size();
			for (int j : cityCount[i]) {
				industryCity.emplace_back(j);
			}
		} else if (cityCount[i].size()) {
			std::vector<int> passedCount(n);
			for (int j : industryCity) {
				for (int k : travelPassCount[j].second) {
					passedCount[k]++;
				}
			}

			std::vector<std::pair<int,int>> nextCityPotential;
			for (int j = 0; j < cityCount[i].size(); j++) {
				nextCityPotential.emplace_back(passedCount[cityCount[i][j]], cityCount[i][j]); 
			}

			for (int j = 0; j < nextCityPotential.size(); j++) {
				if (!k) {
					break;
				} else {
					industryCity.emplace_back(nextCityPotential[j].second);
					k--;
				}
			}

			break;

		}
	}

	std::vector<int> cityPassedCount(n);

	for (int i : industryCity) {
		for (int j : travelPassCount[i].second) {
			cityPassedCount[j]++;
		}
	}

	for (int i : industryCity) {
		cityPassedCount[i] = 0;
	}

	int count = 0;
	for (int i : cityPassedCount) {
		count+=i;
	}

	std::cout << count + start << std::endl;

}




int main() {

	int T = 1;

	for (int i = 0; i < T; i++) {
		populate();
	}
}
