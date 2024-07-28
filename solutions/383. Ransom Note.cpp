#include <unordered_map>
#include <string>

typedef std::unordered_map<char, int> MCI;
class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        MCI ransom, mag;
        for(const char& c : ransomNote) ransom[c]++;
        for(const char& c : magazine) mag[c]++;

        for(const auto& [k, v] : ransom) if(v > mag[k]) return false;
        
        return true;
        
    }
};