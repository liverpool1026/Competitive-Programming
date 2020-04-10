#include <iostream>
#include <vector>
#include <map>


int maxSubArray(std::vector<int>& nums) {
	std::map<std::pair<int, int>, int> a;
	int maxValue = 0;
	int count = 0;
	
	for (int num : nums) {
	    	for (int i = count; i < nums.size(); i++) {
			a[{count, i}] += num;
			if (a[{count, i}] > maxValue) {
		    		maxValue = a[{count, i}];
			}

			for (int j = 0; j < count; j++) {
				a[{j, i}] += num;
				if (a[{j, i}] > maxValue) {
					maxValue = a[{j, i}];
				}
			}
	    	}
	    	count++;
	}

	return maxValue;
}

int main() {
	std::vector<int> a{-2,1,-3,4,-1,2,1,-5,4};
	std::cout << maxSubArray(a) << "\n";
}
