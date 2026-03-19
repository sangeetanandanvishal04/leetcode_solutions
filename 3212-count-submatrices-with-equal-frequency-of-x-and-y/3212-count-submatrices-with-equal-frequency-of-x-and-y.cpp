class Solution {
private:
    int solve(vector<vector<int>>& prefixX, vector<vector<int>>& prefixY, int rows, int cols) {
        int cnt = 0;

        for(int i=1; i<=rows; i++){
            for(int j=1; j<=cols; j++){
                if(prefixX[i][j] == prefixY[i][j] && prefixX[i][j] > 0){
                    cnt++;
                }
            }
        }

        return cnt;
    }

public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> prefixX(rows+1, vector<int>(cols+1, 0));
        vector<vector<int>> prefixY(rows+1, vector<int>(cols+1, 0));

        for(int i=1; i<=rows; i++){
            for(int j=1; j<=cols; j++){
                prefixX[i][j] = prefixX[i-1][j] + 
                                prefixX[i][j-1] - 
                                prefixX[i-1][j-1] + 
                                (grid[i-1][j-1] == 'X' ? 1 : 0);

                prefixY[i][j] = prefixY[i-1][j] + 
                                prefixY[i][j-1] - 
                                prefixY[i-1][j-1] + 
                                (grid[i-1][j-1] == 'Y' ? 1 : 0);
            }
        }

        return solve(prefixX, prefixY, rows, cols);
    }
};