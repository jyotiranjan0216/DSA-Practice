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
        for(int i = 0; i < size; i++) {
            ans = min(ans, answer(matrix, size-1, i, dp));
        }
        return ans;
    }
};