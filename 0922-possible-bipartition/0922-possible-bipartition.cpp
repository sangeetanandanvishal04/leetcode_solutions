class Solution {
private:
    bool isBipartite(int node, vector<vector<int>>& adj, vector<int>& color, int c){
        color[node] = c;

        for(auto adjNode: adj[node]){
            if(color[adjNode] == -1){
                if(isBipartite(adjNode, adj, color, !c) == false){
                    return false;
                }
            }
            else if(color[adjNode] == color[node]){
                return false;
            }
        }

        return true;
    }    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto it: dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> color(n+1, -1);
        for(int i=1; i<=n; i++){
            if(color[i] == -1){
                if(isBipartite(i, adj, color, 0) == false){
                    return false;
                }
            }
        }

        return true;
    }
};