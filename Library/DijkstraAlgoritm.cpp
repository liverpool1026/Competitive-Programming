#include <iostream>
#include <vector>


void populate(const std::vector<std::vector<int>>& route, std::vector<std::pair<int, int>>& distance, const std::vector<int>& visited, int start) {
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
		populate(route, distance, visited, minIndex);
	}

	std::vector<int> shortestPath;
	while (end != start) {
		shortestPath.emplace_back(end);
		end = distance[end].second;
	}

	shortestPath.emplace_back(start);

	return std::vector<int>(shortestPath.rbegin(), shortestPath.rend());


}


int main() {
	std::vector<std::vector<int>> route(4, std::vector<int>(4));

	route[0][1] = 2;
	route[1][0] = 2;

	route[0][2] = 1;
	route[2][0] = 1;

	route[0][3] = 3;
	route[3][0] = 3;


	std::cout << "Route\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << route[i][j] << " ";
		}
		std::cout << "\n";
	}

	std::vector<int> a, b;
	a = getShortestPath(route, 1, 2);
	std::cout << "1 to 2\n";
	for (int i : a) {
		std::cout << i << " ";
	}
	std::cout << "\n";
	b = getShortestPath(route, 2, 3);
	std::cout << "2 to 3\n";
	for (int i : b) {
		std::cout << i << " ";
	}
	std::cout << "\n";

}



