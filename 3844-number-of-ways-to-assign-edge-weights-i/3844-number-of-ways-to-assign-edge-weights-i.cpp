class Solution {
private:
    static const int MOD = 1e9 + 7;
    long long modPow(long long a, long long e){
        long long r = 1;
        while(e){
            if(e & 1){
                r = (r * a) % MOD;
            }
            
            a = (a * a) % MOD;
            e >>= 1;
        }
            
        return r;
    }

    int getMaxDepth(const vector<vector<int>>& adjList) {
        int n = adjList.size() - 1; 
        vector<int> depth(n+1, -1);
        queue<int> q;
        depth[1] = 0;
        q.push(1);

        int maxDepth = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adjList[u]){
                if(depth[v] == -1){
                    depth[v] = depth[u] + 1;
                    maxDepth = max(maxDepth, depth[v]);
                    q.push(v);
                }
            }
        }
        
        return maxDepth;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<vector<int>> temp = edges;

        int n = temp.size()+1;
        vector<vector<int>> adjList(n+1);

        for(auto edge: temp){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int maxDepth = getMaxDepth(adjList);

        return (int)modPow(2, maxDepth-1);
    }
};