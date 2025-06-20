class DisjointSet{
public:
vector<int> parent;
    DisjointSet(int V){
        parent.resize(V+1);
        for(int i=0; i<V+1; i++){
            parent[i] = i;
        }
    }

    int findUPar(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = findUPar(parent[x]);
    }

    void unionByNone(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu != pv){
            parent[pu] = pv;
        }
    }
};

class Solution {
public:    
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        
        // Step 1: Get max row and col to know the number of nodes.
        for(auto it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        //Step 2: Create graph and add them into map
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> mpp;
        for(auto it: stones){
            int node = it[0];
            int adjNode = it[1] + maxRow + 1;
            ds.unionByNone(node, adjNode);
            mpp[node] = 1;
            mpp[adjNode] = 1;
        }
        
        //Step 3: Count connected Components;
        int cnt = 0;
        for(auto it: mpp){
            int node = it.first;
            if(ds.findUPar(node) == node){
                cnt++;
            }
        }
        
        return stones.size() - cnt;
    }
};