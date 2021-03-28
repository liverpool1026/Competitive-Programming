#include <iostream>
#include <vector>

using namespace std;


vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> vec;
        vector<int> lastIndex(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            vec.emplace_back(nums[i][0]);
            lastIndex[i] = 0;
            int count = 1;
            
            for (int j = i - 1; j >= 0; j--) {
               if (nums[j].size() > count) { 
                    vec.emplace_back(nums[j][count]);
                   lastIndex[j] = count;
               }
                count++;
            }
        }
        
//         for (int i = 1; i < nums[nums.size() - 1].size(); i++) {
//             vec.emplace_back(nums[nums.size() - 1][i]);
//             lastIndex[nums.size() - 1] = i;
//             int count = i+1;
//             for (int j =(int)nums.size() - 2; j >= 0; j--) {
//                 if (nums[j].size() > count) { 
//                     vec.emplace_back(nums[j][count]);
//                     lastIndex[j] = count;
//                 }
//                 count++;
//             }
//         }
        
        for (int i = nums.size() - 1; i >= 0; i++) {
            for (int j = lastIndex[i]; j < nums[i].size(); j++) {
                vec.emplace_back(nums[i][j]);
                lastIndex[i] = j;
                int count = j+1;
                for (int k = i - 1; k >= 0; k--) {
                    if (nums[k].size() > count) { 
                        vec.emplace_back(nums[k][count]);
                        lastIndex[k] = count;
                    }
                    count++;
                }
                
            }
        }
        
        return vec;
}


int main() {
	vector<vector<int>> vec;

	vec.emplace_back(vector<int>({1,2,3}));
	vec.emplace_back(vector<int>({4,5,6}));
	vec.emplace_back(vector<int>({7,8,9}));
	findDiagonalOrder(vec);
}
