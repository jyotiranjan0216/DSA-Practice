class Solution {
public:
    int countPaths(int m, int n, vector<vector<int>>& dp) {
        if(m ==0 && n == 0) return 1;
        if(dp[m][n] != -1) return dp[m][n];
        int left = 0, up = 0;
        if(n-1 >= 0)
            left = countPaths(m, n-1, dp);
        if(m-1 >= 0)
            up = countPaths(m-1, n, dp);
        return dp[m][n] = left + up;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(m-1, n-1, dp);
    }
};