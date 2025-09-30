class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;

        for(auto neigh: adj[node]){
            if(!vis[neigh]){
                dfs(neigh, adj, vis);
            }
        }
    }    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        dfs(0, rooms, vis);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                return false;
            }
        }

        return true;
    }
};