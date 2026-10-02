class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto road: roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        vector<pair<long long, long long>> distance(n, {0, LLONG_MAX});
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        distance[0] = {1, 0};
        int mod = (int)(1e9+7);
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int node = top.second;
            long long dist = top.first;
            for(auto it: adj[node]) {
                long long totalDist = (dist + it.second) ;
                int curNode = it.first;
                if(totalDist == distance[curNode].second) {
                    distance[curNode].first = (distance[curNode].first + distance[node].first) % mod;
                }
                else if(totalDist < distance[curNode].second) {
                    pq.push({totalDist, curNode});
                    distance[curNode].first = distance[node].first;
                    distance[curNode].second = totalDist;
                }
            }
        }
        return distance[n-1].first;
    }
};