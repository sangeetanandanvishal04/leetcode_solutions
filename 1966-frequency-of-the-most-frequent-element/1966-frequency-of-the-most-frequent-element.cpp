class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i=0, j=0;
        long long sum = 0;
        int maxEle = 0;

        while(j < n){
            sum += nums[j];

            while((long long)(j-i+1) * (long long)nums[j] - sum > (long long)k){
                sum -= nums[i];
                i++;
            }

            maxEle = max(maxEle, j-i+1);
            j++;
        }

        return maxEle;
    }
};