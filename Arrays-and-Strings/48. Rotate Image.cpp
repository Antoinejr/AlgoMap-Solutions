class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();
        //mirror along leading diagonal
        for(int r = 0; r < R; r++) {
            for( int c = r+1; c < C; c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }

        //mirror y axis
        for(int r = 0; r < R; r++) {
            for( int c = 0; c < C/2; c++) {
                swap(matrix[r][c], matrix[r][C-c-1]);
            }
        }
    }
};
