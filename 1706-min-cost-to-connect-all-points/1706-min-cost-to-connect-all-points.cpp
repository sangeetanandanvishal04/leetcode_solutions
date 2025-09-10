class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{cost, idx}
        pq.push({0, 0});
        vector<int> vis(n, 0);
        vector<int> dist(n, 1e8);
        
        int minCost = 0;
        while(!pq.empty()){
            int cost = pq.top().first;
            int u = pq.top().second; 
            pq.pop();

            if(vis[u]){
                continue;
            }

            minCost += cost;
            vis[u] = 1;

            for(int v=0; v<n; v++){
                if(!vis[v]){
                    int dis = abs(points[u][0]-points[v][0]) + abs(points[u][1]-points[v][1]);
                    if(dis < dist[v]){
                        dist[v] = dis;
                        pq.push({dis, v});
                    }
                }
            }
        }

        return minCost;
    }
};