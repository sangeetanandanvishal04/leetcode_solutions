class Solution {
private:
    void Solve(int idx, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans){
        if(target < 0){
            return;
        }
        if(idx == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        ds.push_back(candidates[idx]);
        Solve(idx, candidates, target - candidates[idx], ds, ans);
        ds.pop_back();

        Solve(idx+1, candidates, target, ds, ans);
    }    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        Solve(0, candidates, target, ds, ans);
        return ans;
    }
};