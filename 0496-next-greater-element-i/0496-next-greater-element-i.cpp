class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) {
            int curr = nums1[i];
            int cnt = -1e9, j = 0;
            for(; j < nums2.size(); j++) {
                if(cnt == -1 && nums2[j] > curr) {
                    cnt = nums2[j];
                    break;  
                } 
                if(nums2[j] == curr) cnt = -1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};