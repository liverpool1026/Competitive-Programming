#include <iostream>
#include <vector>

int find(const std::vector<int>& nums, int low, int high, int k) {
        int middle =  (low + high) / 2;
	if (k == nums[high]) {
		return high;
	} else if (k == nums[low]) {
	 	return low;
	} else if (k == nums[middle]) {
            return middle;
        } else if (low == middle) {
		return -1;
	} else {
            int value = -1;
            if (nums[low] < nums[middle]) {
                //left sorted
                if (k >= nums[low]) {
                    //look at left
                    value = find(nums, low, middle, k);
                } else {
                    // look at right
                    value = find(nums, middle, high, k);
                }
            } else  {
                // right sorted
                if (k > nums[middle]) {
                    //look at right
                    value = find(nums, middle, high, k);
                } else {
                    //look at left
                    value = find(nums, low, middle, k);
                }
            }
            return value;
        }
}


int search(std::vector<int>& nums, int target) {
        return find(nums, 0, nums.size() - 1, target);
}


int main() {
	std::vector<int> vec = {1,3};
	std::cout << search(vec, 3);


}
