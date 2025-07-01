class Solution {
private:
    bool isValid(int nrow, int ncol, int n){
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < n;
    }    
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; //{tmax, {row, col}}
        pq.push({max(0, grid[0][0]), {0, 0}});

        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};

        while(!pq.empty()){
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == n-1){
                return time;
            }

            for(int k=0; k<4; k++){
                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                if(isValid(nrow, ncol, n) && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    pq.push({max(time, grid[nrow][ncol]), {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};