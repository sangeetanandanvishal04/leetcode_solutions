class Solution {
private:
    vector<int> drow = {-1, 0, +1, 0};
    vector<int> dcol = {0, -1, 0, +1};
    
    int bfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid, int m, int n){
        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;
        
        int count = 0;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            count++;

            for(int i=0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return count;
    }    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int maxi = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int a = bfs(i, j, vis, grid, m, n);
                    maxi = max(maxi, a);
                }
            }
        }

        return maxi;
    }
};
