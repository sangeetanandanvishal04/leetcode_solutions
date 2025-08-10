class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int c) {
        color[node] = c;
        for(int neighbor: graph[node]){
            if(color[neighbor] == -1){
                if(dfs(graph, color, neighbor, !c) == false){
                    return false;
                }
            } 
            else if(color[neighbor] == color[node]){  
                return false;
            }
        }

        return true;
    }       
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(!dfs(graph, color, i, 0)){
                    return false;
                }
            }
        }
        return true;
    }
};