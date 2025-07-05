class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        for(int num: nums){
            if(num <= k){
                k++;
            }
            else{
                break;
            }
        }

        return k;
    }
};