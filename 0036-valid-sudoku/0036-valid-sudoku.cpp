class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i=0; i<9; i++){
            if(i != row && board[i][col] == ch){
                return false;
            }
        }

        for(int j=0; j<9; j++){
            if(j != col && board[row][j] == ch){
                return false;
            }
        }

        int delrow = row-(row%3);
        int delcol = col-(col%3);
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if((i+delrow) != row && (j+delcol) != col && board[i+delrow][j+delcol] == ch){
                    return false;
                }
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