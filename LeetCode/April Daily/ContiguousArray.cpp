#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

int findMaxLength(std::vector<int>& nums) {
	std::map<int, std::pair<int, int>> counting;
        
        int count = 0;
        int maxIndex = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                count++;
            } else {
                count--;
            }
            
            if (count) {
                if (counting[count].first != 0) {
                    counting[count].second = i;
                } else {
                    counting[count].first = i;
                }
            } else {
                maxIndex = i+1;
            }
            
            
        }
      
	std::cout << "Count: " << maxIndex << "\n";
        for (auto const &x : counting) {
		std::cout << x.first << ": " << x.second.second  << "|" << x.second.first << "\n";
            if (x.second.second - x.second.first > maxIndex) {
                    maxIndex = x.second.second - x.second.first;
            }
        }
        
        return maxIndex;
        
}

int main() {
	//std::std::vector<int> vec = {0,1,0,1,1,1,0,0,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,0,0,1,0,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,1,1,0,1,0,0,1,1,1,1,1,0,0,1,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,1,1,0,1,1,1,1,0,1,1,0,0,0,1,1};


	std::vector<int> vec = {0, 0, 1};
	std::cout << findMaxLength(vec) << std::endl;
}
