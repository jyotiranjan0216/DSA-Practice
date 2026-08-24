class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxCons = 0;
        for(auto it: nums) {
            if(mp.find(it) != mp.end()) continue;
            int prev = 0, next = 0;
            if(mp.find(it-1) != mp.end()) prev = mp[it-1];
            if(mp.find(it+1) != mp.end()) next = mp[it+1];
            maxCons = max(maxCons, (prev+next+1));
            mp[it] = (prev+next+1);
            // while(prev) {
                mp[it-prev] = (prev+next+1);
                // prev--;
            // }
            // while(next) {
                mp[it+next] = (prev+next+1);
                // next--;
            // }
        }
        return maxCons;
    }
};