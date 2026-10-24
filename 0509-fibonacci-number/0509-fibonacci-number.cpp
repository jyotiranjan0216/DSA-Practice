class Solution {
public:
    int fibonacci(int n, vector<int>& dp) {
        if(n <= 1) return dp[n] = n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fib(n-1)+ fib(n-2);  
    }

    int fib(int n) {
        vector<int> dp(n+1, -1);
        return fibonacci(n, dp);
    }
};