class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int maxi = arr[0];
        int noDel = arr[0];
        int oneDel = INT_MIN;

        for(int i=1; i<n; i++){
            if(oneDel != INT_MIN){
                oneDel = max(noDel, oneDel+arr[i]);
            }
            else{
                oneDel = noDel;
            }
            
            noDel = max(arr[i], noDel + arr[i]);
            maxi = max(maxi, max(noDel, oneDel));
        }

        return maxi;
    }
};