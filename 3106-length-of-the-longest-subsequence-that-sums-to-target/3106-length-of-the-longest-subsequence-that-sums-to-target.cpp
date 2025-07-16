class Solution {
private:
    int Solve(int idx, int target, vector<int>& nums, vector<vector<int>>& memo){
        if(target == 0){
            return 0;
        }
        if(idx == 0){
            if(nums[0] == target){
                return 1;
            }
            return INT_MIN;
        }

        if(memo[idx][target] != -1){
            return memo[idx][target];
        }

        int notTake = Solve(idx-1, target, nums, memo);
        int take = INT_MIN;
        if(nums[idx] <= target){
            take = max(take, 1 + Solve(idx-1, target-nums[idx], nums, memo));
        }

        return memo[idx][target] = max(notTake, take);    
    }    
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> memo(n+1, vector<int>(target+1, -1));
        int ans = Solve(n-1, target, nums, memo);
        return ans < 0? -1: ans;
    }
};