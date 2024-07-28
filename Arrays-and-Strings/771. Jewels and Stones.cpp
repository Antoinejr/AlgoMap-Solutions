class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelMap(jewels.begin(), jewels.end());
        int result = 0;
        for(const char& c : stones) {
            if(jewelMap.find(c) != jewelMap.end()) result++;
        }
        return result;  
    }
};