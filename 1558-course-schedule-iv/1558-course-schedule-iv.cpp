class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjMatrix(numCourses, vector<int>(numCourses, 0));

        for(auto pre: prerequisites){
            int a = pre[0];
            int b = pre[1];

            adjMatrix[a][b] = 1;
        }

        for(int k=0; k<numCourses; k++){
            for(int i=0; i<numCourses; i++){
                if(adjMatrix[i][k] == 0){
                    continue;
                }

                for(int j=0; j<numCourses; j++){
                    if(adjMatrix[k][j] == 1){
                        adjMatrix[i][j] = 1;
                    }
                }
            }
        }
        
        vector<bool> ans;
        for(auto query: queries){
            int u = query[0];
            int v = query[1];
            ans.push_back(adjMatrix[u][v]);
        }

        return ans;
    }
};