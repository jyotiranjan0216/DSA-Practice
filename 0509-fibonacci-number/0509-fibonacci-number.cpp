class Solution {
public:
    int fibonacci(int n, vector<int>& dp) {
        if(n <= 1) return dp[n] = n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fibonacci(n-1, dp)+ fibonacci(n-2, dp);  
    }

    int fib(int n) {
        vector<int> dp(n+2, -1);
        dp[0] = 0, dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        // return fibonacci(n, dp);
    }
};