class Solution {
private:
    int Solve(int idx, vector<int>& nums, int curOr, int maxOr){
        if(idx < 0){
            if(curOr == maxOr){
                return 1;
            }
            return 0;
        }

        int l = Solve(idx-1, nums, curOr, maxOr);
        int r = Solve(idx-1, nums, curOr | nums[idx], maxOr);
        
        return l+r;
    }    
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int num: nums){
            maxOr |= num;
        }

        int n = nums.size();
        return Solve(n-1, nums, 0, maxOr);
    }
};