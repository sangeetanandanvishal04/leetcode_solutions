class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = -1;
        
        for(int i=0; i<n; i++){
            if(nums[i] < mini){
                mini = nums[i];
            }
            else if(mini != nums[i]){
                maxi = max(maxi, abs(mini-nums[i]));
            }
        }

        return maxi;
    }
};