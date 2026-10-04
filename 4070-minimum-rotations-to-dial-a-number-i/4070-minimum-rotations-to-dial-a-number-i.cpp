class Solution {
public:
    int minRotations(string s) {
        int ans = 0, prev = '0';
        for(int i = 0; i < s.length(); i++) {
            int rotate = abs(s[i]-prev);
            cout << rotate << endl;
            if(rotate > 5) ans += (10 - rotate);
            else ans += rotate;
            prev = s[i];
        }
        return ans;
    }
};