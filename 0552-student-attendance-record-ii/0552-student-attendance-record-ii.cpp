class Solution {
private:
    const int MOD = 1e9 + 7;
    int Solve(int day, int absent, int late, vector<vector<vector<int>>>& memo){
        if(absent == 2 || late == 3){
            return 0;
        }
        if(day == 0){
            return 1;
        }

        if(memo[day][absent][late] != -1){
            return memo[day][absent][late];
        }
        
        int pr = Solve(day-1, absent, 0, memo) % MOD;
        int abs = Solve(day-1, absent+1, 0, memo) % MOD;
        int lt = Solve(day-1, absent, late+1, memo) % MOD;

        return memo[day][absent][late] = ((pr+abs) % MOD + lt) % MOD;
    }    
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(2, vector<int>(3, -1)));

        return Solve(n, 0, 0, memo);
    }
};