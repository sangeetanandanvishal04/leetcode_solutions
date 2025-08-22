class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minRow = grid.size();
        int maxRow = -1; 
        int minCol = grid[0].size(); 
        int maxCol = -1;

        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1){
                    if(r < minRow) {
                        minRow = r;
                    }    
                    if(r > maxRow){
                        maxRow = r;
                    }    
                    if(c < minCol){
                        minCol = c;
                    }    
                    if(c > maxCol){
                        maxCol = c;
                    }    
                }
            }
        }

        int height = maxRow - minRow + 1;
        int width = maxCol - minCol + 1;

        return height*width;
    }
};