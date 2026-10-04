class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int> ans(n);
        for(int src = 0; src < n; src++) {
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, src});
            dist[src] = 0;
            while(!pq.empty()) {
                auto top = pq.top();
                pq.pop();
                int node = top.second, d = top.first;
                if(dist[node] < d) continue;
                for(auto it: adj[node]) {
                    int totalDist = it.second + d;
                    int adjNode = it.first;
                    if(totalDist <= distanceThreshold && totalDist < dist[adjNode]) {
                        dist[adjNode] = totalDist;
                        pq.push({totalDist, adjNode});
                    }
                }
            }
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(i == src) continue;
                if(dist[i] != INT_MAX) cnt++; 
            }
            ans[src] = cnt;
        }
        int answer = 0, mini = INT_MAX;
        for(int i = 0; i < n; i++) {
            cout << ans[i];
            if(mini >= ans[i]) {
                mini = ans[i];
                answer = i;
            }
        }
        return answer;
    }
};