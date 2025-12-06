class Solution {
private:
    bool dfs(vector<vector<int>>& adjList, vector<int>& vis, int curNode, int dest){
        if(curNode == dest){
            return true;
        }

        vis[curNode] = 1;

        for(auto neighbor: adjList[curNode]){
            if(vis[neighbor] == -1){
                if(dfs(adjList, vis, neighbor, dest)){
                    return true;
                }
            }
        }

        return false;
    }    
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<int> vis(n, -1);

        return dfs(adjList, vis, source, destination); 
    }
};