#include <iostream>
#include <string>
#include <map>


int createSchedule(int testIndex) {
	int N;
	std::cin >> N;
	std::map<std::pair<int, std::pair<int, int>>, int> activityEntry;
	int CEndTime = 0;
	int JEndTime = 0;
	std::map<int, std::string> assignSchedule;


	for (int i = 0; i < N; i++) {
		int startTime, endTime;
		std::cin >> startTime >> endTime;
		activityEntry.insert({{startTime, {endTime, i}}, i});
	}

	for (auto const& x : activityEntry) {
		if (x.first.first >= CEndTime) {
			CEndTime = x.first.second.first;
			assignSchedule.insert({x.second, "C"});
		} else if (x.first.first >= JEndTime) {
			JEndTime = x.first.second.first;
			assignSchedule.insert({x.second, "J"});
		} else {
			// No valid person can take it
			std::cout << "Case #" << testIndex << ": IMPOSSIBLE\n";
			return 0;
		}
	}

	std::cout << "Case #" << testIndex << ": ";
	for (auto const& x : assignSchedule) {
		std::cout << x.second;
	}
	std::cout << "\n";
	return 0;

}

int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		createSchedule(i+1);
	}

}
