class Solution {
private:
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, -1, 0, 1};

    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& vis, int m, int n){
        vis[row][col] = true;

        for(int k=0; k<4; k++){
            int nrow = row + drow[k];
            int ncol = col + dcol[k];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && heights[nrow][ncol] >= heights[row][col]){
                dfs(nrow, ncol, heights, vis, m, n);
            }
        }
    }    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        for(int j=0; j<n; j++){
            dfs(0, j, heights, pacific, m, n); 
            dfs(m-1, j, heights, atlantic, m, n); 
        }

        for(int i=0; i<m; i++){
            dfs(i, 0, heights, pacific, m, n);
            dfs(i, n-1, heights, atlantic, m, n);
        }
        
        vector<vector<int>> ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};