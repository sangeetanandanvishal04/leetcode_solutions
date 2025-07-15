class Solution {
private:
    void solve(int idx, vector<int>& arr, int size, vector<vector<int>> &result, vector<int> &ds){
        
        if(idx == arr.size()){
            if(ds.size() == size){
                result.push_back(ds);
            }
            return;
        }

        ds.push_back(arr[idx]);
        solve(idx+1, arr, size, result, ds);
        ds.pop_back();
        solve(idx+1, arr, size, result, ds);
    }     
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> ds;

        vector<int> arr;
        for(int i=1; i<=n; i++){
            arr.push_back(i);
        }

        solve(0, arr, k, result, ds);

        return result;
    }
};