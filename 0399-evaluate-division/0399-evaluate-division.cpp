class Solution {
private:
    void dfs(string node, string dest, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& vis, double tempVal, double& finalVal){
        
        vis.insert(node);
        if(node == dest){
            finalVal = tempVal;
            return;
        }

        for(auto neigh: graph[node]){
            if(vis.find(neigh.first) == vis.end()){
                dfs(neigh.first, dest, graph, vis, tempVal*neigh.second, finalVal);;
            }
        }
    }    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        int n = equations.size();
        for(int i=0; i<n; i++){
            string u = equations[i][0];
            string v = equations[i][1]; 
            double edW = values[i];

            graph[u][v] = edW;
            graph[v][u] = 1.0 / edW;
        }
        
        vector<double> ans;
        for(auto query: queries){
            string start = query[0];
            string end = query[1];

            if(graph.find(start) == graph.end() || graph.find(end) == graph.end()){
                ans.push_back(-1.0);
            }
            else{
                unordered_set<string> vis;
                double tempVal = 1.0, finalVal = -1.0;
                dfs(start, end, graph, vis, tempVal, finalVal);
                ans.push_back(finalVal);
            }
        }

        return ans;
    }
};