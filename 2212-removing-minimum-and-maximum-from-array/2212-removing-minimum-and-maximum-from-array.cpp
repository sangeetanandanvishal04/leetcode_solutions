class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int max_ele = INT_MIN, min_ele = INT_MAX;
        int max_idx = -1, min_idx = -1;

        for(int i=0; i<n; i++){
            if(nums[i] > max_ele){
                max_ele = nums[i];
                max_idx = i;
            }

            if(nums[i] < min_ele){
                min_ele = nums[i];
                min_idx = i;
            }
        }

        int min_deletions = INT_MAX;
        min_deletions = min(min_deletions, max(min_idx, max_idx)+1);

        min_deletions = min(min_deletions, max(n-min_idx, n-max_idx));

        min_deletions = min(min_deletions, min(min_idx, max_idx)+1 + n-max(min_idx, max_idx));

        return min_deletions;
    }
};