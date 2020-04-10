#include <iostream>
#include <vector>


int maxProfit(std::vector<int>& prices) {
	int profit = 0;
	int buyPrice = -1;
	int size = (int) prices.size();

        for (int i = 0; i < size - 1; i++) {
            if (prices[i] < prices[i+1]) {
                if (buyPrice < 0) {
		    std::cout << "Buy at: " << prices[i] << "\n";
                    buyPrice = prices[i];
                }
            } else if (prices[i] > prices[i+1]) {
                if (buyPrice >= 0) {
		    std::cout << "Sell at: " << prices[i] << "\n";
                    profit = profit + prices[i] - buyPrice;
                    buyPrice = -1;
                }
            }
        }
        
        if (buyPrice >= 0 && prices.size()) {
	    std::cout << "Sell at: " << prices.back() << "\n";
            profit = profit + prices.back() - buyPrice;
        }
        return profit;

}


int main() {
	std::vector<int> a = {2, 1, 2, 0, 1};
	std::cout << maxProfit(a) << "\n";
}

