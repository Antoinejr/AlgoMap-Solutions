#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int findClosestNumber(std::vector<int>& nums) {
        int N = nums.size(), dist = INT_MAX;

        for (int i = 0; i < N; i++)
        {
            if(abs(nums[i]) <= abs(dist)) {
                dist = (abs(nums[i]) == dist) ? std::max(dist, nums[i]) : nums[i];
            }
        }
        return dist;

        
    }
};
