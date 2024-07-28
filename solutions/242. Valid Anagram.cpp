#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        int sArr[26], tArr[26], N = s.size(), M = t.size();
        if(N != M) return false;

        for(const char& c : s) sArr[c-'a']++;
        for(const char& c : t) tArr[c-'a']++;

        for(int i = 0; i < 26; i++ ) if(sArr[i] != tArr[i]) return false;
        return true;

    }
};