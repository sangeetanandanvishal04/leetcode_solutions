class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int prev = 0;

        for(int num: nums){
            int missing = num - prev - 1;
            if(k <= missing){
                return prev + k;
            }

            k -= missing;
            prev = num;
        }

        return prev + k;
    }
};