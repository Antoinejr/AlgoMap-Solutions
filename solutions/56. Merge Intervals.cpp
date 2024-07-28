#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>> answer;
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>&b)
        {
            return a[0] < b[0];
        });
        answer.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            if(answer.back()[1] >= intervals[i][0]) {
                answer.back()[1] = std::max(answer.back()[1], intervals[i][1]);
            }
            else answer.push_back(intervals[i]);
        }
        return answer;        
    }
};
