class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int k = 1;
        int zeros = 0, maxLen = 0;
        int l=0, r=0;

        while(r<n){
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
                maxLen = max(maxLen, (r-l+1)-zeros);
            }

            r++;
        }

        if(zeros == 0){
           return n-1;
        } 

        return maxLen;
    }
};