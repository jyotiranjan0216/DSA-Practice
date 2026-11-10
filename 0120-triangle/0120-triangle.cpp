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
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), INT_MIN));
        return answer(0, 0, triangle.size(), triangle, dp);
    }
};