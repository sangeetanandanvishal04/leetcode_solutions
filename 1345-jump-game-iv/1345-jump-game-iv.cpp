class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mpp; // {num -> list{idx}}
        
        for(int i=0; i<n; i++){
            mpp[arr[i]].push_back(i);
        }

        vector<int> vis(n, 0);

        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = 1;

        while(!q.empty()){
            int idx = q.front().first;
            int jump = q.front().second;
            q.pop();

            if(idx == n-1){
                return jump;
            }

            if(idx+1 < n && !vis[idx+1]){
                q.push({idx+1, jump+1});
                vis[idx+1] = 1;
            }

            if(idx-1 >= 0 && !vis[idx-1]){
                q.push({idx-1, jump+1});
                vis[idx-1] = 1;
            }

            for(auto it: mpp[arr[idx]]){
                if(!vis[it] && it != idx){
                    q.push({it, jump+1});
                    vis[it] = 1;
                }
            }

            mpp[arr[idx]].clear();
        }

        return -1;
    }
};