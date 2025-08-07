class Solution {
private:
    bool isLeaf(int node, vector<vector<int>>& adj){
        if(node == 1){
            return adj[node].empty();
        }
        return adj[node].size() == 1;
    }    
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n+1);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<pair<int, pair<int, double>>> q; //{src, {time, probablity}}
        q.push({1, {0, 1.0}});
        vector<int> vis(n+1, 0);
        vis[1] = 1;

        while(!q.empty()){
            int node = q.front().first;
            int time = q.front().second.first;
            double prob = q.front().second.second;
            q.pop();

            if(time == t || isLeaf(node, adj)){
                if(node == target){
                    return prob;
                }
                continue;
            }

            int cnt = 0;
            for(auto it: adj[node]){
                if(!vis[it]){
                    cnt++;
                }
            }

            if(cnt == 0){
                if(node == target){
                    return prob;
                }
                continue;
            }
            
            double nextProb = prob / cnt;
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, {time+1, nextProb}});
                }
            }
        }

        return 0.0;
    }
};