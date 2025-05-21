class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        for(int num: nums){
            mini = min(mini, num);
        }

        int minOp = 0;
        for(int num: nums){
            minOp += abs(mini-num);
        }

        return minOp;
    }
};