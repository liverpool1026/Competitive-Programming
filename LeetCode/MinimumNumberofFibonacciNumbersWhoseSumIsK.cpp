#include <iostream>
#include <vector>

std::vector<int> generateFibonacciNumbers(int k) {

        if (k < 3) {
		std::vector<int> fib;
            for (int i = 0; i < k; i++) {
                fib.emplace_back(1);
            }
            return fib;
        } else {
		std::vector<int> fib = {1, 1};
            int currentIndex = 1;
            
            while (fib[currentIndex] < k) {
                currentIndex++;
                fib.emplace_back(fib[currentIndex - 1] + fib[currentIndex - 2]);
            }
            return fib;
        }
}

int findMinFibonacciNumbers(int k) {

	std::vector<int> fib = generateFibonacciNumbers(k);

	std::vector<int> dp(k+2);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i < k+1; i++) {
            for (int j = 1; j < fib.size(); j++) {
                if (i >= fib[j]) {
                    if (dp[i]) {
                        dp[i] = std::min(dp[i - fib[j]] + 1, dp[i]);
                    } else {
                        dp[i] = dp[i - fib[j]] + 1;
                    }
                } else {
                    break;
                } 
            }
        }
        
        return dp[k];
        
}


int main() {
	std::cout << findMinFibonacciNumbers(7) << "\n";
	std::cout << findMinFibonacciNumbers(10) << "\n";
	std::cout << findMinFibonacciNumbers(19) << "\n";
	std::cout << findMinFibonacciNumbers(9083494) << "\n";
}

