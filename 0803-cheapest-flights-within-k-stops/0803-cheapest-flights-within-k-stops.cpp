class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if(src == dst){
            return 0;
        }
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight: flights){
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            adj[u].push_back({v, price});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        //{stops, {node, price}}
        queue<pair<int, pair<int, int>>> q; 

        q.push({0, {src, 0}});        
        
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int price = q.front().second.second;
            q.pop();

            if(stops > k){
                continue;
            }

            for(auto it: adj[node]){
                int adjNode = it.first;
                int edW = it.second;

                if(price + edW < dist[adjNode] && stops <= k){
                    dist[adjNode] = price + edW;
                    q.push({stops+1, {adjNode, price + edW}});
                } 
            }
        }

        if(dist[dst] == INT_MAX){
            return -1;
        }

        return dist[dst];
    }
};