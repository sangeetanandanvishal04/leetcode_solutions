class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for(auto wall: walls){
            grid[wall[0]][wall[1]] = 2; 
        }

        for(auto guard: guards){
            grid[guard[0]][guard[1]] = 1; 
        }
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int drow[] = {-1, 0, 1, 0}; 
        int dcol[] = {0, 1, 0, -1};

        for(auto guard: guards){
            int row = guard[0];
            int col = guard[1];

            for(int k=0; k<4; k++){
                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                while(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                    if(grid[nrow][ncol] == 1 || grid[nrow][ncol] == 2){
                        break;
                    }

                    vis[nrow][ncol] = true;
                    nrow += drow[k];
                    ncol += dcol[k];
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};