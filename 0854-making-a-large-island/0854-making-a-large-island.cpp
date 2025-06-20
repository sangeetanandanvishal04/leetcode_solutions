class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int V){
        size.resize(V, 1);
        parent.resize(V);
        for(int i=0; i<V; i++){
            parent[i] = i;
        }
    }

    int findUPar(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = findUPar(parent[x]);
    }

    void unionBySize(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);

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
private:
    bool isValid(int nrow, int ncol, int n){
        return nrow>=0 && nrow<n && ncol>=0 && ncol<n;
    }    
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};

        //Step 1: Build the existing graph
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 0){
                    continue;
                }

                int node = row*n + col;
                for(int k=0; k<4; k++){
                    int nrow = row + drow[k];
                    int ncol = col + dcol[k];
                    
                    int adjNode = nrow*n + ncol;
                    
                    if(isValid(nrow, ncol, n) && grid[nrow][ncol] == 1){
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        
        //Step 2: Change every zero -> 1 and check the size;
        int maxSize = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 1){
                    continue;
                }
                
                unordered_set<int> st; // store Ultimate Parent
                for(int k=0; k<4; k++){
                    int nrow = row + drow[k];
                    int ncol = col + dcol[k];
                    
                    if(isValid(nrow, ncol, n) && grid[nrow][ncol] == 1){
                        int adjNode = nrow*n + ncol;
                        st.insert(ds.findUPar(adjNode));
                    }
                }

                int sizeTotal = 0;
                for(auto it: st){
                    sizeTotal += ds.size[it];
                }

                maxSize = max(maxSize, sizeTotal+1);
            }
        }

        for(int node=0; node<n*n; node++){
            maxSize = max(maxSize, ds.size[ds.findUPar(node)]);
        }

        return maxSize;
    }
};