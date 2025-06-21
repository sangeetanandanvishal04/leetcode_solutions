class DisjointSet{
public:
    vector<int> parent;
    DisjointSet(int V){
        parent.resize(V+1);
        for(int i=0; i<=V; i++){
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        pair<int, int> edge;
        int V = edges.size();

        DisjointSet ds(V);

        for(auto it: edges){
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionByNone(u, v);
            }
            else{
                edge = {u, v};
            }
        }

        return {edge.first, edge.second};
    }
};