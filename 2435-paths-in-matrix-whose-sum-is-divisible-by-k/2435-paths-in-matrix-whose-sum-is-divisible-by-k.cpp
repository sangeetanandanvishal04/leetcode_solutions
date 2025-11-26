class Solution {
int mod = 1e9 + 7;    
private:
    int Solve(int i, int j, vector<vector<int>>& grid, int k, int sum, vector<vector<vector<int>>>& dp){
        if(i==0 && j==0){
            if((sum+grid[i][j]) % k == 0){
                return 1;
            }
            return 0;
        }
        
        if(i<0 || j<0){
            return 0;
        }

        if(dp[i][j][sum%k] != -1){
            return dp[i][j][sum%k];
        }

        int up = Solve(i-1, j, grid, k, sum+grid[i][j], dp) % mod;
        int left = Solve(i, j-1, grid, k, sum+grid[i][j], dp) % mod;

        return dp[i][j][sum%k] = (up + left)%mod;
    }    
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        //vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        //return Solve(m-1, n-1, grid, k, 0, dp);

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                for(int sum=0; sum<k; sum++){
                    if(dp[i][j][sum] == 0){
                        continue;
                    }    

                    if(i+1<m){
                        int newSum = (sum + grid[i+1][j]) % k;
                        dp[i+1][j][newSum] = (dp[i+1][j][newSum] + dp[i][j][sum]) % mod;
                    }

                    if(j+1<n){
                        int newSum = (sum + grid[i][j+1]) % k;
                        dp[i][j+1][newSum] = (dp[i][j+1][newSum] + dp[i][j][sum]) % mod;
                    }
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};