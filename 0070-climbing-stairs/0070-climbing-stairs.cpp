class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int secondLast = 1, last = 2;
        for(int i = 3; i <= n; i++) {
            int curStair = last+ secondLast;
            secondLast = last;
            last = curStair;
        }
        return last;
    }
};