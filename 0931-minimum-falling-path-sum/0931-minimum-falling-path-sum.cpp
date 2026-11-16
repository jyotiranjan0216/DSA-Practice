class Solution {
public:
    int answer(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp) {
        if(row == 0) {
            return matrix[row][col];
        }
        if(dp[row][col] != -1e9) return dp[row][col];
        int lu = INT_MAX, u = INT_MAX, ru = INT_MAX;
        if(col-1 >= 0) lu = answer(matrix, row-1, col-1, dp);
        u = answer(matrix, row-1, col, dp);
        if(col+1 < matrix.size()) ru = answer(matrix, row-1, col+1, dp);
        return dp[row][col] = matrix[row][col] + min(lu, min(u, ru));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int size = matrix.size();
        vector<vector<int>> dp(size, vector<int>(size, -1e9));
        int ans = INT_MAX;
        //-------------------Memoization--------------
        // for(int i = 0; i < size; i++) {
        //     ans = min(ans, answer(matrix, size-1, i, dp));
        // }
        // return ans;

        //--------------------Tabulation--------------
        for(int i = 0; i < size; i++) {
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1; i < size; i++) {
            for(int j = 0; j < size; j++) {
                int lu = INT_MAX, u = INT_MAX, ru = INT_MAX;
                if(j-1 >= 0) lu = dp[i-1][j-1];
                u = dp[i-1][j];
                if(j+1 < size) ru = dp[i-1][j+1];
                dp[i][j] = min(lu, min(u, ru)) + matrix[i][j];
            }
        }
        return *min_element(dp[size-1].begin(), dp[size-1].end());
    }
};