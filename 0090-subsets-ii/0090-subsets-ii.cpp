class Solution {
private:
    void Solve(vector<int>& nums, vector<vector<int>>& ans, vector<int> ds, int idx){
        ans.push_back(ds);
        int n = nums.size();
        for(int i=idx; i<n; i++){
            if(i > idx && nums[i] == nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            Solve(nums, ans, ds, i+1);
            ds.pop_back();
        }
    }    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;

        Solve(nums, ans, ds, 0);
        return ans;
    }
};