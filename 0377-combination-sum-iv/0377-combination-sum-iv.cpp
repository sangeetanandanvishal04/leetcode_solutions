class Solution {
private:
    int solve(int idx, int target, vector<int>& nums, unordered_map<int, int> &memo){
        if(target == 0){
            return 1;
        }

        if(memo.find(target) != memo.end()){
            return memo[target];
        }
        
        int ans = 0, n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] <= target){
                ans += solve(i, target-nums[i], nums, memo);
            }
        } 

        return memo[target] = ans;  
    }  
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> memo;
        return solve(0, target, nums, memo);
    }
};