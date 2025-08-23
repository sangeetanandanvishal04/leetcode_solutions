class NumMatrix {
public:
    vector<vector<int>> prefSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefSum.assign(m+1, vector<int>(n+1, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                prefSum[i+1][j+1] = matrix[i][j] + prefSum[i][j+1] + prefSum[i+1][j] - prefSum[i][j]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefSum[row2+1][col2+1] - prefSum[row1][col2+1] - prefSum[row2+1][col1] + prefSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */