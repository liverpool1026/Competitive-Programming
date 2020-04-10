#include <iostream>
#include <map>
#include <vector>

int coinChange(std::vector<int>& coins, int amount) {
	std::map<int, int> coinCount; //<amount, coinCount>

	if (amount == 0) {
		return 0;
	}

	coinCount.insert({0, 0});

	for (int i = 1; i <= amount; i++) {
	    int min = -1;
	    for (int coin : coins) {
		if (coinCount.find(i-coin) != coinCount.end()) {
		    if (min == -1 || coinCount[i-coin] + 1 < min) {
			min = coinCount[i-coin] + 1;
		    }
		}
	    }
	    
	    if (min != -1) {
		coinCount.insert({i, min});
	    }
	}

	return coinCount[amount] == 0 ? -1 : coinCount[amount];
}


int main() {
	std::vector<int> vec = {2};


	std::cout << coinChange(vec, 11) << "\n";
}
