class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long count = 0, cnt = 0;
        unordered_map<int, long long> mpp;
        mpp[0] = 1;

        for(int num: nums){
            if(num % modulo == k){
                cnt++;
            }    

            int rem = cnt % modulo;
            int need = (rem-k+modulo) % modulo;

            count += mpp[need];
            mpp[rem]++;
        }

        return count;
    }
};