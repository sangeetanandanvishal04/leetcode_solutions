class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i=0; i<9; i++){
            if(i != row && board[i][col] == ch){
                return false;
            }
            
            if(i != col && board[row][i] == ch){
                return false;
            }

            if((3*(row/3) + i/3) != row && (3*(col/3) + i%3) != col &&  board[3*(row/3) + i/3][3*(col/3) + i%3] == ch){
                return false;
            }
        }
        return true;
    } 
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    if(!isValid(board, i, j, board[i][j])){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};