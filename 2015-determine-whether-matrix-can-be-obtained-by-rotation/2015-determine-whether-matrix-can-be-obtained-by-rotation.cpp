class Solution {
private:
    vector<vector<int>> rotate90(vector<vector<int>> mat){
        int n = mat.size();

        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j < n/2; j++){
                int temp = mat[i][j];
                mat[i][j] = mat[i][n-j-1];
                mat[i][n-j-1] = temp;
            }
        }

        return mat;
    }    
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        for(int i=0; i<4; i++){
            if(mat == target){
                return true;
            }

            mat = rotate90(mat);
        }
        
        return false;
    }
};