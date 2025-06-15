class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int maxVal = INT_MIN;
        for(int num: nums){
            maxVal = max(maxVal, num);
        }
        
        vector<int> left(maxVal+1, 0);
        vector<int> right(maxVal+1, 0);

        for(int num : nums){
            right[num]++;
        }

        int n = nums.size();

        long long ans = 0;
        for(int i=0; i<n; i++){
            right[nums[i]]--;
            
            long long targ = 2LL*nums[i];
            if(targ <= maxVal){
                ans = (ans + 1LL * left[targ] * right[targ]) % MOD;
            }
            
            left[nums[i]]++;
        }

        return int(ans);
    }
};