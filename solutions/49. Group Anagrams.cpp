#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

// Improvement: Instead of sorting (MlogM) we can create an array of size 26 filling in the
// the number of occurence then hashing the array to create a haskey O(M)


// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> mp;

//         for(const string& word : strs) {
//             string key = word;
//             sort(key.begin(), key.end());
//             mp[key].push_back(word);
//         }

//         vector<vector<string>> result;

//         for(const auto& [k, v] : mp) {
//             result.push_back(v);
//         }

//         return result;
//     }
// };


struct vector_hash {
    template <class T>
    size_t operator() (const vector<T>& v) const {
        size_t h1 = 0;
        for(const T& x : v) {
            std::hash<T> hasher;
            h1 = hasher(x) + 0x9e3779b9 + (h1 << 6) + (h1 >> 2);
        }
        return h1;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, vector_hash> mp;

        for(const string& word : strs) {
            vector<int> sMp(26,0); 
            for(const char& c : word) {
                int val = c - 'a';
                sMp[val]++;
            }
            mp[sMp].push_back(word);
        }

        vector<vector<string>> result;
        for(const auto& [k, v] : mp) result.push_back(v);
        
        return result;
    }
};