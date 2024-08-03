#include <unordered_map>
#include <vector>

using namespace std;
typedef unordered_map<int, int> MII;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        MII mp;
        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if(mp.find(diff) != mp.end()) return {i, mp[diff]};
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};