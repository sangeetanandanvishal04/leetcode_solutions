class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = -1;
        int maxArea = -1;
        for(auto dim: dimensions){
            int diag = dim[0]*dim[0] + dim[1]*dim[1];
            int area = dim[0]*dim[1];
            if(diag > maxDiag){
                maxDiag = diag;
                maxArea = area;
            }
            else if(diag == maxDiag){
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};