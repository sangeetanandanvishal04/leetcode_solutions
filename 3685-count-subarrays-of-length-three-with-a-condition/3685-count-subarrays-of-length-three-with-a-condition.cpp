class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=2;

        int cnt = 0;
        while(r < n){
            if(2*(nums[l]+nums[r]) == nums[r-1]){
                cnt++;
            }

            r++;
            l++;
        }

        return cnt;
    }
};