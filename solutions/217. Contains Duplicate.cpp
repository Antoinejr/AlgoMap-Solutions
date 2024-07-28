#include <unordered_map>
#include <vector>
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> mp;
        for(const int& i : nums) mp[i]++;
        
        for(const auto&[k,v] : mp) if(v>1) return true;
        
        return false;

    }
};