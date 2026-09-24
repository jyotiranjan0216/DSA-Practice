class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if(grid[0][0] == 1) return -1;
        vector<vector<int>> dist;
        for(int i = 0; i < n; i++) {
            vector<int> vec;
            for(int j = 0; j < n; j++) {
                vec.push_back(INT_MAX);
            }
            dist.push_back(vec);
        }
        
        queue<vector<int>> q;
        q.push({1, 0, 0});
        dist[0][0] = 1;
        int arr[] = {-1, -1, 0, -1, 1, 1, 0, 1, -1};
        while(!q.empty()) {
            auto vec = q.front();
            q.pop();
            int d = vec[0];
            int i = vec[1], j = vec[2];
            if(i == (n-1) && j == (n-1)) break;
            for(int index = 0; index < 8; index++) {
                int x = i + arr[index], y = j + arr[index+1];
                // cout << x << "===" << y << endl;
                if(x >= 0 && x < n && y >= 0 && y < n) {
                    if(grid[x][y] == 0) {
                        if(dist[x][y] > d+1) {
                            dist[x][y] = d+1;
                            q.push({dist[x][y], x, y});
                            cout << dist[x][y] <<"- ("<< x <<", "<< y <<")"<<endl;
                        }
                    }
                }
            }
            cout << "===========" <<endl;
        }
        if(dist[n-1][n-1] == INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};