class Solution {
private:
    int findMaxElementIdx(vector<vector<int>>& mat, int n, int col){
        int maxIdx = -1;
        int maxi = INT_MIN;

        for(int i=0; i<n; i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                maxIdx = i;
            }
        }

        return maxIdx;
    }   
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            int maxElementIdx = findMaxElementIdx(mat, n, mid);
            int left = mid-1 >= 0? mat[maxElementIdx][mid-1] : -1;
            int right = mid+1 < m? mat[maxElementIdx][mid+1]: -1;

            if(mat[maxElementIdx][mid] > left && mat[maxElementIdx][mid] > right){
                return {maxElementIdx, mid};
            }
            else if(right > mat[maxElementIdx][mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return {-1, -1};
    }
};