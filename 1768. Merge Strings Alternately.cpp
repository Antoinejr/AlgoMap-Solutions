class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int N = word1.size(), M = word2.size();
        int n = 0, m = 0;
        string res = "";

        while(n < N && m < M) {
            if (n == m) {
                res += word1[n++];
            }
            else {
                res += word2[m++];
            }
        }
        if ( n == N) {
            while (m < M) res += word2[m++];
        }else {
            while (n < N) res += word1[n++];
        }

        return res;

        
    }
};
