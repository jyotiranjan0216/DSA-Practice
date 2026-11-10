class Solution {
public:
    int answer(int row, int col, int size, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(row == size-1) return triangle[row][col];
        if(dp[row][col] != INT_MIN) return dp[row][col];
        int down = answer(row+1, col, size, triangle, dp);
        int diagonal = answer(row+1, col+1, size, triangle, dp);
        return dp[row][col] = min(down, diagonal) + triangle[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), INT_MIN));
        // return answer(0, 0, triangle.size(), triangle, dp);
        for(int i = 0; i < size; i++) {
            dp[size-1][i] = triangle[size-1][i];
        }
        for(int i = size-2; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
                int d = dp[i+1][j];
                int dg = dp[i+1][j+1];
                dp[i][j] = min(d, dg) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};