class Solution {
private:
    void solve(int idx, vector<int>& arr, int target, int size, vector<vector<int>> &result, vector<int> &ds){
        
        if(idx == arr.size()){
            if(target == 0 && ds.size() == size){
                result.push_back(ds);
            }
            return;
        }

        if(arr[idx] <= target){
            ds.push_back(arr[idx]);
            solve(idx+1, arr, target-arr[idx], size, result, ds);
            ds.pop_back();
        }
        solve(idx+1, arr, target, size, result, ds);
    }  
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> ds;
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        solve(0, arr, n, k, result, ds);

        return result;
    }
};