class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> dp(n, 1);
        int maxLen = 1;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(pairs[i][0] > pairs[j][1] && 1+dp[j] > dp[i]){
                    dp[i] = 1+dp[j]; 
                }
                maxLen = max(maxLen, dp[i]);
            }
        } 

        return maxLen;
    }
};