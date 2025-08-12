class Solution {
private:
    int solve(int i, int j, string s, vector<vector<int>>& dp) {
        if(i > j){
            return 0; 
        }    
        if(i == j){
            return 1;
        } 

        if(dp[i][j] != -1){
            return dp[i][j];
        }    

        int res = 1 + solve(i+1, j, s, dp);

        for(int k = i+1; k<=j; k++){
            if(s[i] == s[k]){
                res = min(res, solve(i+1, k-1, s, dp) + solve(k, j, s, dp));
            }
        }

        return dp[i][j] = res;
    }    
public:
    int strangePrinter(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, s, dp);
    }
};