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

    bool bfs(vector<vector<int>>& graph, vector<int>& color, int start){
        queue<int> q;
        q.push(start);
        color[start] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int neighbor: graph[node]){
                if(color[neighbor] == -1){ 
                    color[neighbor] = !color[node];
                    q.push(neighbor);
                } 
                else if(color[neighbor] == color[node]){
                    return false; 
                }
            }
        }

        return true;
    }    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  

        /*for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(!dfs(graph, color, i, 0)){
                    return false;
                }
            }
        }
        
        return true;*/

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(!bfs(graph, color, i)){
                    return false;
                }
            }
        }

        return true;
    }
};