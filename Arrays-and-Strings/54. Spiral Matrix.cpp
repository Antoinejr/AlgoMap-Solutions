class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();
        vector<int> answer;
        int direction = 0;
        int left = 0, right = C-1, top = 0, bottom = R-1;

        while(answer.size() != R*C) {
            if(direction == 0) {
                int j = left;
                while(j <= right) answer.push_back(matrix[top][j++]);
                top++;
            }
            else if(direction == 1) {
                int i = top;
                while(i <= bottom) answer.push_back(matrix[i++][right]);
                right--;
            }
            else if(direction == 2) {
                int j = right;
                while(j >= left) answer.push_back(matrix[bottom][j--]);
                bottom--;
            }
            else if(direction == 3) {
                int i = bottom;
                while(i >= top) answer.push_back(matrix[i--][left]);
                left++;
            }
            direction = (direction + 1) % 4;
        }
        return answer;       
    }
};
