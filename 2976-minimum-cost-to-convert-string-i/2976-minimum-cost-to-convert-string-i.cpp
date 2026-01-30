class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = 26;
        vector<vector<long long>> adjMat(n, vector<long long>(n, INT_MAX));
        
        for(int i=0; i<n; i++){
            adjMat[i][i] = 0;
        }
        
        for(int i=0; i<original.size(); i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int w = cost[i];
            adjMat[u][v] = min(adjMat[u][v], (long long)w);
        }

        for(int via=0; via<n; via++){
            for(int u=0; u<n; u++){
                for(int v=0; v<n; v++){
                    if(adjMat[u][via] != INT_MAX && adjMat[via][v] != INT_MAX){
                        adjMat[u][v] = min(adjMat[u][v], adjMat[u][via] + adjMat[via][v]);
                    }
                }
            }
        }

        long long totalCost = 0;
        for (int i=0; i<source.length(); i++){
            int src = source[i] - 'a';
            int tar = target[i] - 'a';
            if(src != tar){
                if(adjMat[src][tar] == INT_MAX){
                    return -1;
                }
                totalCost += adjMat[src][tar];
            }
        }
        return totalCost;
    }
};