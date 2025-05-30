class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));

        int left = 0, right = n-1;
        int top = 0, bottom = n-1;
        int num = 1;

        while(left <= right && top <= bottom){
            for(int i=left; i<=right; i++){
                matrix[top][i] = num;
                num++;
            }
            top++;

            for(int i=top; i<=bottom; i++){
                matrix[i][right] = num;
                num++;
            }
            right--;

            if(left <= right){
                for(int i=right; i>=left; i--){
                    matrix[bottom][i] = num;
                    num++;
                }
                bottom--;
            }

            if(top <= bottom){
                for(int i=bottom; i>=top; i--){
                    matrix[i][left] = num;
                    num++;
                }
                left++;
            }
        }

        return matrix;
    }
};