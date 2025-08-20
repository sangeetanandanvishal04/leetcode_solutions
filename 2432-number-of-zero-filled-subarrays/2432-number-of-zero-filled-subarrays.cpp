class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        long long sum = 0;
        long long cnt = 0;
        while(r < n){
            sum += abs(nums[r]);
            while(sum > 0){
                sum -= abs(nums[l]);
                l++;
            }

            if(sum == 0){
                cnt += (r-l+1);
            }

            r++;
        }

        return cnt;
    }
};