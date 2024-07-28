#include <string>
class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int N = s.size(), i = 0;
        for (char c : t) {
            if (c == s[i]) i++;
        }
        return i == N; 
    }
};