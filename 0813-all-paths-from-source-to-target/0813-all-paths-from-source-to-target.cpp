class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<vector<int>> q;
        q.push({0});

        vector<vector<int>> ans;
        
        while(!q.empty()){
            auto vec = q.front();
            q.pop();

            if(vec.back() == n-1){
                ans.push_back(vec);
                continue;
            }

            int node = vec.back();
            for(auto adjNode: graph[node]){
                vec.push_back(adjNode);
                q.push(vec);
                vec.pop_back();
            } 
        }

        return ans;
    }
};