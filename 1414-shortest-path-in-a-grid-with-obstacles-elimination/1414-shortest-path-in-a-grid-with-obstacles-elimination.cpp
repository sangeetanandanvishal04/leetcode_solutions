class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int manhattan = m - 1 + n - 1;
        if(k >= manhattan){
            return manhattan;
        }    

        vector<vector<int>> vis(m, vector<int>(n, -1));
        queue<pair<int, pair<int, int>>> q; // {rem_k, {row, col}};
        q.push({k, {0, 0}});
        vis[0][0] = k;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        
        int steps = 0;
        while(!q.empty()){
            int levelSize = q.size();
            steps++;
            for(int i=0; i<levelSize; i++){
                int rem_k = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;
                q.pop();

                for(int i=0; i<4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if(nrow<0 || nrow>=m || ncol<0 || ncol>=n){
                        continue;
                    }

                    int newRem_k = rem_k - grid[nrow][ncol];
                    if(newRem_k < 0){
                        continue;
                    }

                    if(vis[nrow][ncol] != -1 && vis[nrow][ncol] >= newRem_k){
                        continue;
                    }

                    if(nrow == m-1 && ncol == n-1){
                        return steps;
                    }

                    vis[nrow][ncol] = newRem_k;
                    q.push({newRem_k, {nrow, ncol}});
                } 
            }
        }

        return -1;
    }
};