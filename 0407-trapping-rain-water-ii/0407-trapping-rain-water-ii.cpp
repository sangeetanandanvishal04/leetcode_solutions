class Solution {
public:
    int trapRainWater(vector<vector<int>>& height){
        int m = height.size();
        int n = height[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; //{height, {row, col}}

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            vis[i][0] = 1;
            vis[i][n-1] = 1;
            pq.push({height[i][0], {i, 0}});
            pq.push({height[i][n-1], {i, n-1}});
        }

        for(int i=0; i<n; i++){
            vis[0][i]=1;
            vis[m-1][i]=1;
            pq.push({height[0][i], {0, i}});
            pq.push({height[m-1][i], {m-1, i}});
        }
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        int result=0;
        while(!pq.empty()){
            int h = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol]){
                    result += max(0, h-height[nrow][ncol]);
                    pq.push({max(h, height[nrow][ncol]), {nrow, ncol}});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        return result;
    }
};