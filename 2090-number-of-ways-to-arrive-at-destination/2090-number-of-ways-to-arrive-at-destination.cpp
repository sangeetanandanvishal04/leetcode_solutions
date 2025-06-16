class Solution {    
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(n);
        for(auto road: roads){
            int u = road[0];
            int v = road[1];
            int time = road[2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        int src = 0, goal = n-1;
        vector<long long> dist(n, LLONG_MAX); // time
        dist[src] = 0;
        vector<int> ways(n, 0);
        ways[src] = 1;
        //{time(dist), node}
        priority_queue<pair<long long, int>, 
        vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, src});

        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dis > dist[node]){
                continue;
            }

            for(auto& [adjNode, edW]: adj[node]){
                long long newEdW = dis + edW;

                if(newEdW < dist[adjNode]){
                    dist[adjNode] = newEdW;
                    ways[adjNode] = ways[node];
                    pq.push({newEdW, adjNode});
                }
                else if(newEdW == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return (int)ways[goal] % MOD;
    }
};