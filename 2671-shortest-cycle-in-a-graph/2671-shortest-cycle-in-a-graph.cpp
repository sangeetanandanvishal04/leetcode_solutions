class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int ans = INT_MAX;
        for(int start=0; start<n; start++){
            vector<int> dist(n, -1), parent(n, -1);
            queue<int> q;

            q.push(start);
            dist[start] = 0;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int neigh: adj[node]){
                    if(dist[neigh] == -1){
                        dist[neigh] = dist[node] + 1;
                        parent[neigh] = node;
                        q.push(neigh);
                    }
                    else if(parent[node] != neigh){
                        ans = min(ans, dist[node]+dist[neigh]+1);
                    }
                }
            }
        }

        return ans == INT_MAX? -1: ans;
    }
};