class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> vec;
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    vec.push_back({i, j});
                }
            }
        }

        for(auto [row, col]: vec){
            for(int i=0; i<m; i++){
                matrix[i][col] = 0;
            }

            for(int i=0; i<n; i++){
                matrix[row][i] = 0;
            }
        }
    }
};