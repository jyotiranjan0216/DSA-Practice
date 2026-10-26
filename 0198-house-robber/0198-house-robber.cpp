class Solution {
public:
    int maxRob(int n, vector<int>& nums, vector<int>& dp) {
        if(n == 0) return nums[0];
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int pick = maxRob(n-2, nums, dp) + nums[n];
        int notPick = maxRob(n-1, nums, dp);
        return dp[n] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return maxRob(nums.size()-1, nums, dp);
    }
};