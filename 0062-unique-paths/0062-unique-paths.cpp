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
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return countPaths(m-1, n-1, dp);
        vector<int> dp(n);
        // for(int i = 0; i < m; i++) {
        //     dp[i][0] = 1;
        // }
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
        }
        for(int i = 1; i < m; i++) {
            vector<int> temp(n, 1);
            for(int j = 0; j < n; j++) {
                if(j == 0) continue;
                temp[j] = dp[j] + temp[j-1];
            }
            dp = temp;
        }
        return dp[n-1];
    }
};