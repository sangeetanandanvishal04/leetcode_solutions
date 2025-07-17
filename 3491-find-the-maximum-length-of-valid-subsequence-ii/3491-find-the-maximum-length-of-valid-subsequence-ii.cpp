class Solution {
private:
    int Solve(int idx, int prev, int modVal, vector<int>& nums, int k, vector<vector<vector<int>>>& memo){
        if(idx < 0){
            return 0;
        }

        if(memo[idx][prev+1][modVal+1] != -1){
            return memo[idx][prev+1][modVal+1];
        }
        
        int ans = Solve(idx-1, prev, modVal, nums, k, memo);

        if(prev == -1){
            ans = max(ans, 1 + Solve(idx-1, idx, -1, nums, k, memo));
        }
        else{
            int curMod = (nums[idx] + nums[prev]) % k;
            if(modVal == -1 || curMod == modVal){
                int nextMod = (modVal == -1)? curMod: modVal;
                ans = max(ans, 1 + Solve(idx-1, idx, nextMod, nums, k, memo));
            }
        }

        return memo[idx][prev+1][modVal+1] = ans;
    }      
public:
    int maximumLength(vector<int>& nums, int k) {
        //int n = nums.size();
        //vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(n+2, vector<int>(1001, -1)));
        //return Solve(n-1, -1, -1, nums, k, memo);

        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(k, 1));
        
        int ans = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int m = (nums[i] + nums[j]) % k;
                dp[i][m] = max(dp[i][m], 1 + dp[j][m]);
                ans = max(ans, dp[i][m]);
            }
        }

        return ans;
    }
};