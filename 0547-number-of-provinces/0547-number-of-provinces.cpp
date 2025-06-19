class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int V){
        size.resize(V, 1);
        parent.resize(V, 0);
        for(int i=0; i<V; i++){
            parent[i] = i;
        }
    }

    int findUParent(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = findUParent(parent[x]);
    }

    void unionByNone(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);

        if(pu == pv){
            return;
        }

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {  
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    ds.unionByNone(i, j);
                }
            }
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i){
                cnt++;
            }
        }

        return cnt;
    }
};