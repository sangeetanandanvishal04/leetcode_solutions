class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(int i=0; i<n; i++){
            dist[i][i] = 0;
        }

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int via=0; via<n; via++){
            for(int u=0; u<n; u++){
                for(int v=0; v<n; v++){
                    if(dist[u][via] != 1e9 && dist[via][v] != 1e9 &&
                    dist[u][via] + dist[via][v] < dist[u][v]){
                        dist[u][v] = dist[u][via] + dist[via][v];
                    }
                }
            }
        }
        
        int city = -1;
        int cnt = 0, maxCnt = INT_MAX;
        for(int i=0; i<n; i++){
            cnt = 0;
            for(int j=0; j<n; j++){
                if(i!=j && dist[i][j] != 1e9 && dist[i][j] <= distanceThreshold){
                    cnt++;
                }
            }

            if(cnt <= maxCnt){
                city = i;
                maxCnt = cnt;
            }
        }

        return city;
    }
};