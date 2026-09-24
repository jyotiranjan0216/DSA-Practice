class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        efforts[0][0] = 0;
        int moves[] = {-1, 0, 1, 0, -1};
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int eff = top[0];
            int row = top[1], col = top[2];
            if(eff > efforts[row][col]) continue;
            for(int i = 0; i < 4; i++) {
                int newRow = row + moves[i], newCol = col + moves[i+1];
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    int curEff = abs(heights[row][col] - heights[newRow][newCol]);
                    curEff = max(curEff, eff);
                    if(curEff < efforts[newRow][newCol]) {
                        efforts[newRow][newCol] = curEff;
                        pq.push({curEff, newRow, newCol});
                    }
                }
            }
        }
        return efforts[m-1][n-1];
    }
};