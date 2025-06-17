class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        
        for(int i=1; i<n; i++){
            for(auto edge: times){
                int u = edge[0];
                int v = edge[1];
                int edW = edge[2];
                
                if(dist[u] != 1e8 && dist[u] + edW < dist[v]){
                    dist[v] = dist[u] + edW;
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