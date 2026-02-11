class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> res(n, 0);
        unordered_map<int, vector<int>> mpp; //{num : list(idx)}
        
        for(int i=0; i<n; i++){
            mpp[arr[i]].push_back(i);
        }
        
        for(auto it: mpp) {
            vector<int> idx_list = it.second;
            int n = idx_list.size();
            for(int i=1; i<n; i++){
                res[idx_list[0]] += abs(idx_list[i]-idx_list[0]);
            }

            for(int i=1; i<n; i++){
                res[idx_list[i]] = res[idx_list[i-1]] - (idx_list[i]-idx_list[i-1])*(n-i-1) + (idx_list[i]-idx_list[i-1])*(i-1);
            }
        }
        
        return res;
    }
};