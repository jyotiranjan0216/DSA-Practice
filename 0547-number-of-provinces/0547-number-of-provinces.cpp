class DSU {
    vector<int> parent, rank;
    
public:
    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int uParent(int a) {
        if(a == parent[a]) return a;
        return parent[a] = uParent(parent[a]);
    }
    
    bool unionByRank(int a, int b) {
        int u_a = uParent(a);
        int u_b = uParent(b);
        if(u_a == u_b) return false;
        
        if(rank[u_a] < rank[u_b]) {
            parent[u_a] = u_b;
        }
        else if(rank[u_a] > rank[u_b]) {
            parent[u_b] = u_a;
        }
        else {
            parent[u_b] = u_a;
            rank[u_a]++;
        }
        return true;
    }
  
    
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU ds(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    ds.unionByRank(i, j);
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(ds.uParent(i) == i) cnt++;
        }
        return cnt;
    } 
};