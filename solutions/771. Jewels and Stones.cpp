#include <unordered_set>
#include <string>
class Solution {
public:
    int numJewelsInStones(std::string jewels, std::string stones) {
        std::unordered_set<char> jewelMap(jewels.begin(), jewels.end());
        int result = 0;
        for(const char& c : stones) {
            if(jewelMap.find(c) != jewelMap.end()) result++;
        }
        return result;  
    }
};