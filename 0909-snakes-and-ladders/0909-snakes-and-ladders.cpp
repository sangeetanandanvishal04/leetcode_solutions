class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> min_rolls(n*n + 1, -1);

        queue<int> q;
        min_rolls[1] = 0;
        q.push(1);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(curr == n*n){
                return min_rolls[curr];
            }

            for(int dice=1; dice<=6; dice++){
                if(curr + dice <= n*n){
                    int next = curr + dice;
                    int row = (next-1) / n;
                    int col = (next-1) % n;

                    int val = board[n-1-row][row%2? n-1-col: col];
                    int new_val = val > 0 ? val: next;
                    if(min_rolls[new_val] == -1){
                        min_rolls[new_val] = min_rolls[curr] + 1;
                        q.push(new_val);
                    }
                }
            }
        }

        return -1;
    }
};