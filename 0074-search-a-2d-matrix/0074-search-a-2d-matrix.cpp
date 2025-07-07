class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        int len = m*n;
        int low = 0, high = len-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            int midRow = mid / n;
            int midCol = mid % n;

            if(mat[midRow][midCol] == target){
                return true;
            }
            else if(mat[midRow][midCol] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return false;
    }
};