class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if(nums.size() == 1) return true;
        int cnt = 0;
        for(int i = nums.size()-1; i >= 0; i--) {
            if(nums[i] >= cnt) cnt = 1;
            else {
                cnt++;
            }
        }
        return cnt == 1;
    }
};