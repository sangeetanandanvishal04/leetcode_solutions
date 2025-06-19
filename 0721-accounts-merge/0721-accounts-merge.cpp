class DisjointSet {
public:
    vector<int> parent;
    DisjointSet(int V){
        parent.resize(V);
        for(int i=0; i<V; i++){
            parent[i] = i;
        }    
    }

    int findUParent(int x) {
        if(x == parent[x]){
            return x;
        }    
        return parent[x] = findUParent(parent[x]);
    }

    void unionByNone(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);
        
        if(pu != pv){
            parent[pu] = pv;
        }    
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mpp; //{email : idx(i)}
        for(int i=0; i<n; i++){
            int m = accounts[i].size();
            for(int j=1; j<m; j++){
                if(mpp.find(accounts[i][j]) != mpp.end()){
                    ds.unionByNone(i, mpp[accounts[i][j]]);
                }
                else{
                    mpp[accounts[i][j]] = i;
                }
            }
        }

        vector<vector<string>> emails(n);
        for(auto it: mpp){
            string email = it.first;
            int node = it.second;

            int ulp_node = ds.findUParent(node);
            emails[ulp_node].push_back(email);
        }
        
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(emails[i].empty()){
                continue;
            }

            sort(emails[i].begin(), emails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(string email: emails[i]){
                temp.push_back(email);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};