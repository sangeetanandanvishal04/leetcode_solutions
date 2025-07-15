class Solution { 
private:
    void Solve(int idx, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i=idx; i<candidates.size(); i++){
            if(i > idx && candidates[i-1] == candidates[i]){
                continue;
            }
            if(candidates[i] > target){
                break;
            }
            ds.push_back(candidates[i]);
            Solve(i+1, candidates, target-candidates[i], ds, ans);
            ds.pop_back();
        }
    }     
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;

        Solve(0, candidates, target, ds, ans);
        return ans;
    }
};