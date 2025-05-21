class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int mod = 12345;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, 1));
        long long int curCal = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                result[i][j] = curCal;
                curCal = (curCal * grid[i][j])%mod;
            }
        }

        curCal = 1;

        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                result[i][j] = (result[i][j] * curCal)%mod;
                curCal = (curCal*grid[i][j])%mod;
            }
        }

        return result;
    }
};