#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
typedef unordered_set<int> SOI; // set of integers
typedef unordered_map<int, SOI> MIS; // map integer to set

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); // Combine hash values
    }
};

typedef unordered_map<pair<int, int>, SOI, pair_hash> MPS; // map pair<int, int> to set
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int R = board.size(), C = board[0].size();
        MIS rowMap, colMap;
        MPS gridMap;
        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                char value = board[r][c];
                if (value == '.') continue; // Skip empty cells
                
                int num = value - '0'; //change to int
                int rGrid = r/3 , cGrid = c/3;
                pair<int, int> tpl = {rGrid, cGrid};

                if(rowMap[r].find(num) != rowMap[r].end()) return false;
                if(colMap[c].find(num) != colMap[c].end()) return false;
                if(gridMap[tpl].find(num) != gridMap[tpl].end()) return false;

                rowMap[r].insert(num);
                colMap[c].insert(num);
                gridMap[tpl].insert(num);
            }
        }
        return true;

    }
};