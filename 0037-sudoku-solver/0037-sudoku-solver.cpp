class Solution {    
private:
    bool isValid(vector<vector<char>>& board, char ch, int row, int col){
        for(int i=0; i<9; i++){
            if(board[i][col] == ch){
                return false;
            }
            
            if(board[row][i] == ch){
                return false;
            }

            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == ch){
                return false;
            }
        }
        return true;
    }

    bool Solve(vector<vector<char>>& board){
        for(int row=0; row < 9; row++){
            for(int col=0; col < 9; col++){
                if(board[row][col] == '.'){
                    for(char ch = '1'; ch <= '9'; ch++){
                        if(isValid(board, ch, row, col) == true){
                            board[row][col] = ch;
                            if(Solve(board) == true){
                                return true;
                            }
                            else{
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }    
public:
    void solveSudoku(vector<vector<char>>& board) {
        Solve(board);
    }
};