class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int k = 3;
        if(nums[0] >= nums[1]){
            return false;
        }    
        int n = nums.size();
        int sign = 1, turns = 0;

        for(int i=1; i<n; i++){
            int delta = nums[i] - nums[i-1];
            if(delta == 0){
                return false;
            }    
            else if(delta*sign < 0){  
                sign *= -1;
                turns++;
            }
        }

        return turns == k - 1;
    }
};