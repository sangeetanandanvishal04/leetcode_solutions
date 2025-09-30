class Solution {  
private:
    void dfs(string node, unordered_map<string, multiset<string>> &graph, vector<string>& ans){
        auto& destSet = graph[node];
        
        while(!destSet.empty()){
            auto it = destSet.begin();
            string next = *it;
            destSet.erase(it); 
            dfs(next, graph, ans);
        }

        ans.push_back(node);
    }     
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        for(auto ticket: tickets){
            graph[ticket[0]].insert(ticket[1]);
        }

        vector<string> ans;
        string start = "JFK";
        dfs(start, graph, ans);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};