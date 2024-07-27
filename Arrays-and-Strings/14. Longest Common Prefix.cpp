#include <string>
#include <vector>
class Solution {
private:
    std::string findCommonPrefix(std::string word1, std::string word2) {
        int N = word1.size(), M = word2.size();
        std::string res = "";
        for(int i = 0; i < std::min(N, M); i++) {
            if(word1[i] != word2[i]) break;
            res += word1[i];
        }
        return res;
    }
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int N = strs.size();
        std::string result = strs[0];

        for(int i = 1; i < N; i++) {
            result = findCommonPrefix(result, strs[i]);
            if(result == "") break;
        }
        return result;        
    }
};