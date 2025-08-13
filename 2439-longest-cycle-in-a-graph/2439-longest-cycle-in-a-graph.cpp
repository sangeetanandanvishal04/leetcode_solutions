class Solution {
private:
    int ans = -1;
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis, vector<int>& steps, int depth){
        vis[node] = 1;
        pathVis[node] = 1;
        steps[node] = depth;

        for(auto neigh: adj[node]){
            if(!vis[neigh]){
                dfs(neigh, adj, vis, pathVis, steps, depth+1);
            }
            else if(pathVis[neigh]){
                ans = max(ans, depth-steps[neigh]+1);
            }
        }

        pathVis[node] = 0;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++){
            if(edges[i] != -1){
                adj[i].push_back(edges[i]);
            }
        }

        vector<int> vis(n, 0), pathVis(n, 0), steps(n, 0);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, adj, vis, pathVis, steps, 0);
            }
        }

        return ans;
    }
};