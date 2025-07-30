class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        int maxLen = 0, curLen = 0;
        for(int num: nums){
            if(num == maxi){
                curLen++;
            }
            else{
                maxLen = max(maxLen, curLen);
                curLen = 0;
            }
        }

        return max(maxLen, curLen);
    }
};