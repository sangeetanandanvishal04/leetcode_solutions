class Solution {
private:
    int Solve(vector<int>& nums, int idx, vector<int>& dp){
        if(idx == 0){
            return nums[0];
        }
        if(idx == 1){
            return max(nums[0], nums[1]);
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        int pick = nums[idx] + Solve(nums, idx-2, dp);
        int notPick = Solve(nums, idx-1, dp);
        return dp[idx] = max(pick, notPick);
    }    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return Solve(nums, n-1, dp);
    }
};