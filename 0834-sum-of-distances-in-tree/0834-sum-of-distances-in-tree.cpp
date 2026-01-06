class Solution {
private:
    void dfs1(int node, int par, vector<vector<int>>& adj, vector<int>& dp, vector<int>&sz){
        for(auto adjNode: adj[node]){
            if(adjNode == par){
                continue;
            }

            dfs1(adjNode, node, adj, dp, sz);
            sz[node] += sz[adjNode];
            dp[node] += dp[adjNode] + sz[adjNode];
        }
    } 

    void dfs2(int node, int par, vector<vector<int>>& adj, vector<int>&sz, int n, vector<int>& ans){
        for(auto adjNode: adj[node]){
            if(adjNode == par){
                continue;
            }

            ans[adjNode] = n + ans[node] - 2*sz[adjNode];
            dfs2(adjNode, node, adj, sz, n, ans);
        }
    }    
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dp(n, 0), sz(n, 1);
        dfs1(0, -1, adj, dp, sz);

        vector<int> ans(n);
        ans[0] = dp[0];
        dfs2(0, -1, adj, sz, n, ans);

        return ans;
    }
};