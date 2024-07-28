class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>&b)
        {
            return a[0] < b[0];
        });
        answer.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            if(answer.back()[1] >= intervals[i][0]) {
                answer.back()[1] = max(answer.back()[1], intervals[i][1]);
            }
            else answer.push_back(intervals[i]);
        }
        return answer;        
    }
};
