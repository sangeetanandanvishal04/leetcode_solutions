class Solution { 
private:
    bool Solve(vector<vector<char>>& board, string word, int row, int col, int idx){
        if(idx == word.size()){
            return true;
        }

        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[idx]){
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#';

        bool found = Solve(board, word, row-1, col, idx+1) || 
                     Solve(board, word, row+1, col, idx+1) ||
                     Solve(board, word, row, col-1, idx+1) ||
                     Solve(board, word, row, col+1, idx+1);

        board[row][col] = temp;

        return found;              
    }     
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j] == word[0] && Solve(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};