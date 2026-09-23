class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, longest = 0;
        int zeros = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) zeros++;
            if(zeros > k) {
                while(nums[start] != 0) {
                    start++;
                }
                start++; zeros--;
            }
            longest = max(longest, (i-start +1));
        }
        return longest;
    }
};