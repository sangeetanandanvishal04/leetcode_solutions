class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        unordered_map<int, int> mpp;
        
        for(int i=0; i<n; i++){
           mpp[x[i]] = max(mpp[x[i]], y[i]);
        }

        if(mpp.size() < 3){
            return -1;
        }
        
        vector<int> arr;
        for(auto [key, val]: mpp){
            arr.push_back(val);
        }

        sort(arr.begin(), arr.end(), greater<int>());
        return arr[0] + arr[1] + arr[2];
    }
};