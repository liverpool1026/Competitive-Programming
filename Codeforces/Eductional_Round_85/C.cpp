#include <iostream>
#include <vector>
#include <set>


void applyDamage(std::vector<std::pair<long long int, long long int>>& vec, int targetIndex, long long int damage, int num, std::set<int>& killed) {
	if (vec[targetIndex].first > 0) {
		vec[targetIndex].first -= damage;
		if (vec[targetIndex].first <= 0) {
			vec[targetIndex].first = 0;
			if (targetIndex == num - 1) {
				applyDamage(vec, 0, vec[targetIndex].second, num, killed);
			} else {
				applyDamage(vec, targetIndex+1, vec[targetIndex].second, num, killed);
			}
			killed.insert(targetIndex);
		}
	}
}


int findNextTarget(const std::vector<std::pair<long long int, long long int>>& vec) {
	int flag = 1;
	int index = 0;
	long long int minValue;
	int size = (int) vec.size();

	for (int i = 0; i < size; i++) {
		if (vec[i].first) {
			if (flag) {
				int nextTarget = i + 1;
				if (i == size -1) {
				       nextTarget = 0;
				}	       
				if (vec[nextTarget].first) {
					minValue = vec[i].first;
					index = i;
					flag = 0;
					continue;
				}
			} else {
				if (vec[i].first < minValue) {
					index = i;
				}
			}
		}
	}

	if (flag) {
		for (int i = 0; i < size; i++) {
			if (vec[i].first) {
				if (flag) {
					minValue = vec[i].first;
					index = i;
					flag = 0;
					continue;
				} else { 
					if (vec[i].first < minValue) {
						index = i;
					}
				}
			}

		}
	}

	return index;
}




int check() {
	int num;
	long long int shots = 0;
	long long int minHealth = 0;
	int currentIndex = 0;
	std::vector<std::pair<long long int, long long int>> vec;
	std::cin >> num;
	std::set<int> killedMons;

	for (int i = 0; i < num; i++) {
		long long int hp, damage;
		std::cin >> hp >> damage;
		if (i == 0) {
			minHealth = hp;
			currentIndex = 0;
		} else {
			if (hp < minHealth) {
				currentIndex = i;
				minHealth = hp;
			}
		}
		vec.push_back({hp, damage});
	}

	while (killedMons.size() != num) {
		applyDamage(vec, currentIndex, minHealth, num, killedMons);
		shots+=minHealth;
		currentIndex = findNextTarget(vec);
		minHealth = vec[currentIndex].first;
	}

	std::cout << shots << std::endl;
	return 0;
}

int main() {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; i++) {
		check();
	}

}
