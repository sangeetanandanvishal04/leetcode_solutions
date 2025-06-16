class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = INT_MIN;
        int mini = nums[0];
        int n = nums.size();

        for(int i=1; i<n; i++){
            maxDiff = max(maxDiff, nums[i]-mini);
            mini = min(mini, nums[i]);
        }

        return maxDiff > 0? maxDiff: -1;
    }
};