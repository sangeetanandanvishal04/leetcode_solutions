class Solution {
private:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple){
        int time = 0;
        for(auto neigh: adj[node]){
            if(neigh != parent){
                int t = dfs(neigh, node, adj, hasApple);
                if(t > 0 || hasApple[neigh]){
                    time += (t + 2);
                }
            }
        }

        return time;
    }    
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(0, -1, adj, hasApple);
    }
};