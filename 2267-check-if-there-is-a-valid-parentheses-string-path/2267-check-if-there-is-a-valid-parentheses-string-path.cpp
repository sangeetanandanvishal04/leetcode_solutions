class Solution {
private:
    bool CheckValidPath(int i, int j, int open, int m, int n, vector<vector<char>>& grid, vector<vector<vector<int>>>& memo){
        if(i >= m || j >= n){
            return false;
        }

        if(grid[i][j] == '('){
            open++;
        }
        else{
            open--;
        }

        if(open < 0){
            return false;
        }

        if(i == m-1 && j == n-1){
            return open == 0;
        }

        if(memo[i][j][open] != -1){
            return memo[i][j][open];
        }

        bool result = CheckValidPath(i, j+1, open, m, n, grid, memo) ||
                      CheckValidPath(i+1, j, open, m, n, grid, memo);

        return memo[i][j][open] = result;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(m+n+1, -1)));
        return CheckValidPath(0, 0, 0, m, n, grid, memo);
    }
};