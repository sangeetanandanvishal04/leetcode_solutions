class Solution {
private:
    int Solve(int idx1, int idx2, string text1, string text2, vector<vector<int>>& memo){
        if(idx1 == 0 || idx2 == 0){
            return 0;
        }

        if(memo[idx1][idx2] != -1){
            return memo[idx1][idx2];
        }

        if(text1[idx1-1] == text2[idx2-1]){
            return memo[idx1][idx2] = 1 + Solve(idx1-1, idx2-1, text1, text2, memo);
        }
        return memo[idx1][idx2] = max(Solve(idx1-1, idx2, text1, text2, memo), 
                   Solve(idx1, idx2-1, text1, text2, memo));
    }    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();

        //vector<vector<int>> memo(n1+1, vector<int>(n2+1, -1));
        //return Solve(n1, n2, text1, text2, memo);
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int idx1=1; idx1<=n1; idx1++){
            for(int idx2=1; idx2<=n2; idx2++){
                if(text1[idx1-1] == text2[idx2-1]){
                    dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                }
                else{
                    dp[idx1][idx2] = max(dp[idx1-1][idx2], dp[idx1][idx2-1]);
                }        
            }
        }

        return dp[n1][n2];
    }
};