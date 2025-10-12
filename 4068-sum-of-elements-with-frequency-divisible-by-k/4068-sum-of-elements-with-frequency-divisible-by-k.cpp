class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int num: nums){
            mpp[num]++;
        }


        int sum = 0;
        for(auto it: mpp){
            int num = it.first;
            int cnt = it.second;
            if(cnt % k == 0){
                sum += (cnt*num);
            }
        }

        return sum;
    }
};