class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int MaxOnes = 0;
        int ones = 0;

        for(int i=0; i<n; i++){
            if(nums[i]){
                ones++;
            }
            else{
                ones = 0;
            }

            MaxOnes = max(MaxOnes, ones);
        }
        
        return MaxOnes;
    }
};