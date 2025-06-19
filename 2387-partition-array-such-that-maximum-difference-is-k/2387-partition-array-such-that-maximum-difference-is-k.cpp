class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int subsequence = 1;
        int start = nums[0];
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]-start > k){
                subsequence++;
                start = nums[i];
            }
        }

        return subsequence;
    }
};