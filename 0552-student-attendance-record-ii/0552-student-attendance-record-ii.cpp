class Solution {
private:
    const int MOD = 1e9 + 7;
    int Solve(int n, int idx, int absent, int late, vector<vector<vector<int>>>& memo){
        if(absent == 2 || late == 3){
            return 0;
        }
        if(idx == n){
            return 1;
        }

        if(memo[idx][absent][late] != -1){
            return memo[idx][absent][late];
        }
        
        int pr = Solve(n, idx+1, absent, 0, memo) % MOD;
        int abs = Solve(n, idx+1, absent+1, 0, memo) % MOD;
        int lt = Solve(n, idx+1, absent, late+1, memo) % MOD;

        return memo[idx][absent][late] = ((pr+abs) % MOD + lt) % MOD;
    }    
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(2, vector<int>(3, -1)));

        return Solve(n, 0, 0, 0, memo);
    }
};