class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map <int,int> mp;
        for(int i = 0; i< nums.size(); i++) {
            int val = nums[i];
            auto it = mp.find(target- val);
            if(it != mp.end()) {
                ans.push_back(it -> second);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};