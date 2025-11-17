class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int gap = 0;
        bool flag = false;
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                if(flag == false){
                    flag = true;
                    gap = 0;
                }
                else if(gap >= k){
                    gap = 0;
                }
                else{
                   return false;
                }
            }
            else{
                gap++;
            }
        }

        return true;
    }
};