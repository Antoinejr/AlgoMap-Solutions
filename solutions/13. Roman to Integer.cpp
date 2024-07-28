#include <iostream>
#include <string>
#include <unordered_map>


class Solution {
public:
    int romanToInt(std::string s) {
        int N = s.size(), n = 0, res = 0;

        std::unordered_map <char, int> mp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        while(n < N) {
            if(s[n] == 'I' &&  (s[n+1] == 'V' || s[n+1] == 'X')) {
                res += mp[s[n+1]] - mp[s[n]];
                n = n + 2;
            }
            else if (s[n] == 'X' && (s[n+1] == 'L' || s[n+1] == 'C')) {
                res += mp[s[n+1]] - mp[s[n]];
                n = n + 2;
            }
            else if(s[n] == 'C' && (s[n+1] == 'D' || s[n+1] == 'M')) {
                res += mp[s[n+1]] - mp[s[n]];
                n = n + 2;  
            } else {
                res += mp[s[n++]];
            }   
        }
        return res;
        
    }
};
