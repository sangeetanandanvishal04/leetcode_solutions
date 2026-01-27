class Solution {
public:
    vector<pair<int, int>> adj[1001];
    int minCostArr[1001], minTimeArr[1001];
    int dijkstra(int src, int dest, int maxTime, vector<int>& passingFees) {
        for(int i=0; i<=dest; i++){
            minCostArr[i] = INT_MAX;
            minTimeArr[i] = INT_MAX;
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // {cost, time, node}

        minCostArr[src] = passingFees[src];
        minTimeArr[src] = 0;
        pq.push({passingFees[src], 0, src});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int cost = top[0];
            int time = top[1];
            int node = top[2];

            if(node == dest){
                return cost;
            }    

            for(auto it: adj[node]){
                int adjNode = it.first;
                int travelTime = it.second;
                int arrivalTime = time + travelTime;
                int arrivalCost = cost + passingFees[adjNode];

                if(arrivalTime > maxTime){
                    continue;
                }    

                if(arrivalCost < minCostArr[adjNode]){
                    minCostArr[adjNode] = arrivalCost;
                    minTimeArr[adjNode] = arrivalTime;
                    pq.push({arrivalCost, arrivalTime, adjNode});
                }
                else if(arrivalTime < minTimeArr[adjNode]){
                    minTimeArr[adjNode] = arrivalTime;
                    pq.push({arrivalCost, arrivalTime, adjNode});
                }
            }
        }

        return minCostArr[dest];
    }

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int t = e[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        int ans = dijkstra(0, n-1, maxTime, passingFees);
        return(ans == INT_MAX ? -1 : ans);
    }
};
