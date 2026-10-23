class DSU{
public: 
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int uParent(int a) {
        if(parent[a] == a) return a;
        return parent[a] = uParent(parent[a]);
    }
    
    void unionBySize(int a, int b) {
        int u_a = uParent(a);
        int u_b = uParent(b);
        if(u_a == u_b) return;
        if(size[u_a] < size[u_b]) {
            parent[u_a] = u_b;
            size[u_b]+= size[u_a];
        }
        else {
            parent[u_b] = u_a;
            size[u_a] += size[u_b];
        }
    }

};

class Solution {
    bool isValid(int a, int b, int n) {
        return a < n && b < n && a >= 0 && b >= 0;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int size = n*n;
        DSU ds(size);
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 0) continue;
                int moves[] = {-1, 0, 1, 0, -1};
                for(int m = 0; m < 4; m++) {
                    int newR = row + moves[m];
                    int newC = col + moves[m+1];
                    if(isValid(newR, newC, n) && grid[newR][newC] == 1) {
                        int index = row*n + col;
                        int newIndex = newR*n + newC;
                        ds.unionBySize(index, newIndex);
                    }
                }
            }
        }
        int largestIsland = 0;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) continue;
                int moves[] = {-1, 0, 1, 0, -1};
                set<int> components;
                for(int m = 0; m < 4; m++) {
                    int newR = row + moves[m];
                    int newC = col + moves[m+1];
                    if(isValid(newR, newC, n) && grid[newR][newC] == 1) {
                        int newIndex = newR*n + newC;
                        components.insert(ds.uParent(newIndex));
                    }
                }
                int isLargest = 1;
                for(auto &it: components) {
                    isLargest += ds.size[it];
                }
                largestIsland = max(largestIsland, isLargest);
            }
        }

        for(int i = 0; i < n*n; i++) {
            largestIsland = max(largestIsland, ds.size[ds.uParent(i)]);
        }
        return largestIsland;
    }
};