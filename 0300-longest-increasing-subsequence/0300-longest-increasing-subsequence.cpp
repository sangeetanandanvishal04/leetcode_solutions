class Solution {
private:
    int Solve(int idx, int prev, vector<int>& nums, vector<vector<int>>& memo){
        if(idx < 0){
            return 0;
        }

        if(memo[idx][prev+1] != -1){
            return memo[idx][prev+1];
        }

        int notTake = Solve(idx-1, prev , nums, memo);
        int take = 0;
        if(prev == -1 || nums[idx] < nums[prev]){
            take = 1 + Solve(idx-1, idx, nums, memo);
        }

        return memo[idx][prev+1] = max(notTake, take);
    }    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //vector<vector<int>> memo(n, vector<int>(n+1, -1));
        //return Solve(n-1, -1, nums, memo);

        /*int maxi = 1;
        vector<int> dp(n, 1);

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;*/

        int len = 1;
        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i=1; i<n; i++){
            if(nums[i] > temp.back()){
                len++;
                temp.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }

        return len;
    }
};