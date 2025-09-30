class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e8));
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        dist[0][0] = 0; //since, grid[0][0] = 0 given;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        while(!dq.empty()){
            int row = dq.front().first;
            int col = dq.front().second;
            dq.pop_front();

            for(int k=0; k<4; k++){
                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                    if(dist[row][col] + grid[nrow][ncol] < dist[nrow][ncol]){
                        dist[nrow][ncol] = dist[row][col] + grid[nrow][ncol];
                        if(grid[nrow][ncol] == 0){
                            dq.push_front({nrow, ncol});
                        }
                        else{
                            dq.push_back({nrow, ncol});
                        }
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};