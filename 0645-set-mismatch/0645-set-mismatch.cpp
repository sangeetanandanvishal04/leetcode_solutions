class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int actual_sum = n*(n+1) / 2;
        int array_sum = 0;
        int unique_sum = 0;

        unordered_set<int> st(nums.begin(), nums.end());

        for(int num: nums){
            array_sum += num;
        }


        for(int num: st){
            unique_sum += num;
        }

        int missing = actual_sum - unique_sum;
        int duplicate = array_sum - unique_sum;

        return {duplicate, missing};
    }
};