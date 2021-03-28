#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void populateShortest(const std::vector<std::vector<int>>& route, std::vector<std::pair<int, int>>& distance, const std::vector<int>& visited, int start) {
        for (int i = 0; i < distance.size(); i++) {
                if (route[start][i] && !visited[i]) {
                        if (distance[i].first != -1) {
                                if (distance[i].first > distance[start].first + route[start][i]) {
                                        distance[i].first = distance[start].first + route[start][i];
                                        distance[i].second = start;
                                }
                        } else {
                                distance[i].first = distance[start].first + route[start][i];
                                distance[i].second = start;
                        }
                }
        }
}

std::vector<int> getShortestPath(const std::vector<std::vector<int>>& route, int start, int end) {
        std::vector<std::pair<int, int>> distance(route.size(), {-1, -1});
        std::vector<int> visited(route.size(), 0);
        distance[start] = {0, 0};

        for (int j = 0; j < route.size(); j++) {
                int minDistance = -1;
                int minIndex = -1;
                for (int i = 0; i < route.size(); i++) {
                        if (distance[i].first != -1 && !visited[i]) {
                                if (minDistance == -1) {
                                        minDistance = distance[i].first;
                                        minIndex = i;
                                } else {
                                        if (minDistance > distance[i].first) {
                                                minDistance = distance[i].first;
                                                minIndex = i;
                                        }
                                }

                        }
                }
                visited[minIndex] = 1;
                populateShortest(route, distance, visited, minIndex);
        }

        std::vector<int> shortestPath;
        while (end != start) {
                shortestPath.emplace_back(end);
                end = distance[end].second;
        }

        shortestPath.emplace_back(start);

        return std::vector<int>(shortestPath.rbegin(), shortestPath.rend());


}


void populate() {

	int n, m, a, b, c;

	std::cin >> n >> m >> a >> b >> c;

	std::vector<int> price(m);

	for (int i = 0; i < m; i++) {
		std::cin >> price[i];
	}

	std::vector<std::vector<int>> route(n, std::vector<int>(n));

	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		route[a-1][b-1] = 1;
		route[b-1][a-1] = 1;
	}

	// Find shortest path
	std::vector<int> firstTrip = getShortestPath(route, a-1, b-1);
	std::vector<int> secondTrip = getShortestPath(route, b-1, c-1);

	std::vector<std::vector<int>> count(n, std::vector<int>(n));

	for (int i = 1; i < firstTrip.size(); i++) {
		count[firstTrip[i-1]][firstTrip[i]]++;
		count[firstTrip[i]][firstTrip[i-1]]++;
	}

	for (int i = 1; i < secondTrip.size(); i++) {
		count[secondTrip[i-1]][secondTrip[i]]++;
		count[secondTrip[i]][secondTrip[i-1]]++;
	}

	std::vector<int> counting;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (count[i][j]) {
				counting.emplace_back(count[i][j]);
			}
		}
	}

	std::sort(counting.rbegin(), counting.rend());
	std::sort(price.begin(), price.end());

	int priceIndex = 0;
	int cost = 0;
	for (int i : counting) {
		cost += i * price[priceIndex++];
	}

	std::cout << cost << std::endl;
}




int main() {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		populate();
	}
}
