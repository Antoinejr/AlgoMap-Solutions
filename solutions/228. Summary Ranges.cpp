#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> result;
        int N = nums.size();

        for(int l = 0; l < N; l++) {
            int r = l+1;
            int add = 1;
            while(r < N && nums[l] + add == nums[r]) {
                add++;
                r++;
            }
            if(add > 1) {
                result.push_back(std::to_string(nums[l])+ "->"+ std::to_string(nums[r-1]));
            } else {
                result.push_back(std::to_string(nums[l]));
            }
            l = r-1;
        }

        return result;    
    }
};