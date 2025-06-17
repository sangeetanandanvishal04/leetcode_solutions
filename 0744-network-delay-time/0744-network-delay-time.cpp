class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto time: times){
            int u = time[0];
            int v = time[1];
            int t = time[2];

            adj[u].push_back({v, t});
        }
        
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                if(time + edW < dist[adjNode]){
                    dist[adjNode] = time + edW;
                    pq.push({time+edW, adjNode});
                }
            }
        }
        
        int maxi = INT_MIN;
        for(int i=1; i<=n; i++){
            if(dist[i] == 1e9){
                return -1;
            }
            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};