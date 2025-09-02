class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid){
        vis[row][col] = 1;

        int m = grid.size();
        int n = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        for(int i=0; i<4; i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol] == 0){
                dfs(nrow, ncol, vis, grid);
            }
        }
    }    
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    if(!vis[i][j] && grid[i][j] == 0){
                        dfs(i, j, vis, grid);
                    }
                }
            }
        }
        
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    count++;
                    dfs(i, j, vis, grid);
                }
            }
        }

        return count;
    }
};