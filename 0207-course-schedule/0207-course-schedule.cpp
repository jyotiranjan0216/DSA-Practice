class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V);
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()) {
            int peek = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[peek]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return cnt == V;
    }
};