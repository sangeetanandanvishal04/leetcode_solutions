class Solution {
private:
    void Solve(vector<vector<int>>& ans, vector<int> ds, vector<int>& nums, int idx){
        ans.push_back(ds);
        int n = nums.size();
        
        for(int i=idx; i<n; i++){
            ds.push_back(nums[i]);
            Solve(ans, ds, nums, i+1);
            ds.pop_back();
        }
    }    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        Solve(ans, ds, nums, 0);
        return ans;
    }
};