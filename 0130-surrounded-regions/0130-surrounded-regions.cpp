class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(board[i][j] == 'O'){
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};