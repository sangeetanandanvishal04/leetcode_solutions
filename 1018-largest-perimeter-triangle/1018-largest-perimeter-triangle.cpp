class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int maxi = INT_MIN;
        for(int i=n-1; i>1; i--){
            if(nums[i] < nums[i-1]+nums[i-2]){
                return nums[i]+nums[i-1]+nums[i-2]; 
            }
        }

        return 0;
    }
};