class Solution {
public:
    bool isConsistent(vector<int> & nums) {
        int mini = nums[0];
        int andd = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int it = nums[i];
            mini = min(mini, it);
            andd &= it;
        }
        // cout << mini <<" " << andd <<endl;
        return mini == andd;
    }
    int countConsistent(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            vector<int> temp;
            for(int j = i; j < nums.size(); j++) {
                temp.push_back(nums[j]);
                if(isConsistent(temp)) ans++;
            }
        }
        return ans;
    }
};