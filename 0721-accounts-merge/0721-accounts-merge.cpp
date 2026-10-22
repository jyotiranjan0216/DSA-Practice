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
    
    void unionByRank(int a, int b) {
        int u_a = uParent(a);
        int u_b = uParent(b);
        if(u_a == u_b) return;
        
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
    }  
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mapOfMails;
        int n = accounts.size();
        DSU ds(n);
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                if(mapOfMails.find(accounts[i][j]) == mapOfMails.end()) {
                    mapOfMails[accounts[i][j]] = i;
                }
                else {
                    ds.unionByRank(mapOfMails[accounts[i][j]], i);
                }
            }
        }

        vector<vector<string>> mergedMails(n);
        for(auto &it: mapOfMails) {
            mergedMails[ds.uParent(it.second)].push_back(it.first);
        }

        vector<vector<string>> finalAccounts;
        for(int i = 0; i < n; i++) {
            if(mergedMails[i].size() == 0) continue;
            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto &it: mergedMails[i]) {
                temp.push_back(it);
            }
            finalAccounts.push_back(temp);
        }
        return finalAccounts;
    }
};