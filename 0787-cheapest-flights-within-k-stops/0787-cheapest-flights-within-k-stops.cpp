class Solution {
public:
    int findCheapestPrice(int V, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(V);
        for(auto vec: edges) {
            adj[vec[0]].push_back({vec[1], vec[2]});
            // adj[vec[1]].push_back({vec[0], vec[2]});
        }
        queue<vector<int>> pq;
        vector<int> dist(V, INT_MAX);
        pq.push({0, src, 0});
        dist[src] = 0;
        while(!pq.empty()) {
            auto it = pq.front();
            int node = it[1];
            int curDist = it[2];
            int stop = it[0];
            pq.pop();
            if(stop > k) continue;
            for(auto vec: adj[node]) {
                int newDist = vec.second + curDist;
                if(dist[vec.first] > newDist && stop <= k) {
                    dist[vec.first] = newDist;
                    pq.push({stop+1, vec.first, newDist});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};