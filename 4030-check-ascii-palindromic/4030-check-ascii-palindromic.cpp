class Solution {
public:
    bool isPalindromic(string s) {
        string str = "";
        for(auto ch: s) {
            int d = (int)ch;
            string st = bitset<8>(d).to_string();
            str = str+ st;
        }
        string str2 = str;
        reverse(str2.begin(), str2.end());
        return str == str2;
    }
};