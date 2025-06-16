class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1){
            return -1;
        }

        int n = grid.size();
        queue<pair<int, pair<int, int>>> q; //{steps, {row, col}}
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        q.push({1, {0, 0}}); // -> steps, src coordinates

        while(!q.empty()){
            int steps = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if(row == n-1 && col == n-1){
                return steps;
            }

            for(int drow=-1; drow<=1; drow++){
                for(int dcol=-1; dcol<=1; dcol++){
                    int nrow = row+drow;
                    int ncol = col+dcol;

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && 
                            grid[nrow][ncol] == 0 && steps+1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = steps + 1;
                        q.push({steps+1, {nrow, ncol}});
                    }
                }
            }
        }

        return -1;
    }
};