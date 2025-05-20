class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int left = 0, right = n-1;
        while(left<m && right>=0){
            if(matrix[left][right] == target){
                return true;
            }
            else if(matrix[left][right] < target){
                left++;
            }
            else{
                right--;
            }
        }
        
        return false;
    }
};