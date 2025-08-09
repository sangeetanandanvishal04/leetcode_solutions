class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int posIdx = 0, negIdx = 0;
        for(int num: nums){
            if(num > 0){
                ans[2*posIdx] = num;
                posIdx++;
            }
            else{
                ans[2*negIdx+1] = num;
                negIdx++;
            }
        }

        return ans;
    }
};