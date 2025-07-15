class Solution {
private:
    int solve(int target, vector<int>& nums, unordered_map<int, int> &memo){
        if(target == 0){
            return 1;
        }

        if(memo.find(target) != memo.end()){
            return memo[target];
        }
        
        int ans = 0, n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] <= target){
                ans += solve(target-nums[i], nums, memo);
            }
        } 

        return memo[target] = ans;  
    }  
public:
    int combinationSum4(vector<int>& nums, int target) {
        //unordered_map<int, int> memo;
        //return solve(target, nums, memo);

        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;

        for(int i=1; i<=target; i++){
            for(int num: nums){
                if(i-num >= 0){
                    dp[i] += dp[i-num];
                }
            }
        }

        return dp[target];
    }
};