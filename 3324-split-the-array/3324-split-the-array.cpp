class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int num: nums){
            mpp[num]++;
            if(mpp[num] > 2){
                return false;
            }
        }

        return true;
    }
};