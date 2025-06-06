class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int l = 0, zeros = 0;

        for(int r=0; r<n; r++){
            if(nums[r] == 0){
                zeros++;
            }
            if(zeros > k){
                if(nums[l] == 0){
                    zeros--;
                }
                l++;
            }

            if(zeros <= k){
                maxLen = max(maxLen, r-l+1);
            }
        }

        return maxLen;
    }
};