class Solution {
private:
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, -1, 0, 1};

    bool dfs(int startRow, int startCol, int row, int col, vector<vector<int>>& vis, vector<vector<int>>& land){
        if(startRow == row){
            return true;
        }    
        vis[startRow][startCol] = 1;

        for(int k=0; k<4; k++){
            int nrow = startRow + drow[k];
            int ncol = startCol + dcol[k];

            if(nrow >= 1 && nrow <= row && ncol >= 1 && ncol <= col && !vis[nrow][ncol] && land[nrow][ncol] == 0){
                if(dfs(nrow, ncol, row, col, vis, land)){
                    return true;
                }
            }
        }

        return false;
    }

    bool isPossible(int row, int col, vector<vector<int>>& land){
        int startCol = 1;
        vector<vector<int>> vis(row+1, vector<int>(col+1, 0));

        while(startCol <= col){
            if(land[1][startCol] == 0 && !vis[1][startCol]){
                if(dfs(1, startCol, row, col, vis, land)){
                    return true;
                }
            }

            startCol++;
        }

        return false;
    }    
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();
        int low = 1, high = n;
        
        while(low <= high){
            int mid = low + (high-low)/2;

            vector<vector<int>> land(row+1, vector<int>(col+1, 0));
            for(int i=0; i<mid; i++){
                land[cells[i][0]][cells[i][1]] = 1;
            }

            if(isPossible(row, col, land)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return high;
    }
};