class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto pre: prerequisites){
            int a = pre[0];
            int b = pre[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto neigh: adj[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
        
        if(topo.size() != numCourses){
            return {};
        }

        return topo;
    }
};