class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for(int num: nums){
            if(num % 2 == 0){
                ans.push_back(-1);
            } 
            else{
                int t = num + 1;
                int lowbit = t & -t;
                ans.push_back(num - (lowbit >> 1));
            }
        }
        
        return ans;
    }
};