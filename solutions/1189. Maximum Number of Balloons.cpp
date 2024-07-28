class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> tMap;
        int result = INT_MAX;
        unordered_map<char, int> balloon = {
            {'b',1},
            {'a',1},
            {'l',2},
            {'o',2},
            {'n',1}
        };
        
        for(const char& c : text) tMap[c]++;
        for(const auto& [k, v] : balloon) {
            result = std::min(result, tMap[k]/v);
        }
        return result;
    }
};