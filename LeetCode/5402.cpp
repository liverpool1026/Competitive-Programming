#include <iostream>
#include <vector>

using namespace std;
int longestSubarray(vector<int>& nums, int limit) {
        vector<vector<pair<int, int>>> dp(nums.size(), vector<pair<int, int>>(nums.size()));
        
        for (int i = 0; i < nums.size(); i++) {
            dp[i][i] = {nums[i], nums[i]};
        }
                                          
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); i++) {
                dp[i][j] = {max(nums[j], dp[i][j-1].first), min(nums[j], dp[i][j-1].second)};
            }
        }
                                            
        int maxValue = 0;
        int maxIndex = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int value = dp[i][j].first - dp[i][j].second;
                if (value <= limit && value >= maxValue && (j-i+1 >= maxIndex)) {
                    maxIndex = j-i+1;
                    value = maxValue;
                }
                

            }
        }
                                     
        
        return maxIndex;
                
    }


int main() {
	vector<int> vec = {8, 2, 4, 7};
	longestSubarray(vec, 4);
}
