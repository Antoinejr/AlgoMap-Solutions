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
        /**
        *int N = strs.size();
        *std::string result = strs[0];

        *for(int i = 1; i < N; i++) {
        *    result = findCommonPrefix(result, strs[i]);
        *    if(result == "") break;
        *}
        *return result;
        **/
        
        std::sort(strs.begin(), strs.end());
        std:string s1 = strs[0], s2 = strs[strs.size()-1];
        int idx = 0;
        while(idx < std::min(s1.size(), s2.size())) {
            if(s1[idx] != s2[idx]) break;
            idx++;
        }  
        return s1.substr(0,idx);   
    }
};
