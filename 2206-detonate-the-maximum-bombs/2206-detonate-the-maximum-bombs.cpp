class Solution {
private:
    int dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;

        int cnt = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                cnt += dfs(it, adj, vis);
            }
        }

        return cnt;
    }    
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++){
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r1 = bombs[i][2];

            for(int j=i+1; j<n; j++){
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                int r2 = bombs[j][2];

                int dx = (x2-x1);
                int dy = (y2-y1);
                long long dist = 1LL*dx*dx + 1LL*dy*dy;

                if(dist <= 1LL*r1*r1){
                    adj[i].push_back(j);
                }
                if(dist <= 1LL*r2*r2){
                    adj[j].push_back(i);
                }
            }
        }

        int maxCnt = 0;
        for(int i=0; i<n; i++){
            vector<int> vis(n, 0);
            int cnt = dfs(i, adj, vis);
            maxCnt = max(maxCnt, cnt);
        }

        return maxCnt;
    }
};