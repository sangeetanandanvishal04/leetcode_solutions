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
        int left = nums[idx] + Solve(nums, idx-2, dp);
        int right = Solve(nums, idx-1, dp);
        return dp[idx] = max(left, right);
    } 

    int SolveDP(vector<int>& nums){
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0], nums[1]);
        }

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        
        int curr = 0;
        for(int i=2; i<n; i++){
            curr = max(prev1, nums[i]+prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }       
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        vector<int> nums1(nums.begin(), nums.end()-1); 
        vector<int> nums2(nums.begin()+1, nums.end());

        vector<int> dp1(nums1.size(), -1);
        vector<int> dp2(nums2.size(), -1);

        return max(Solve(nums1, n-2, dp1), Solve(nums2, n-2, dp2));

        //return max(SolveDP(nums1), SolveDP(nums2));
    }
};