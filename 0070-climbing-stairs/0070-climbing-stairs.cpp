class Solution {  
private:
    int Solve(int n, vector<int>& memo){
        if(n == 0 || n == 1){
            return 1;
        }

        if(memo[n] != -1){
            return memo[n];
        }

        return memo[n] = Solve(n-1, memo) + Solve(n-2, memo);
    }     
public:
    int climbStairs(int n) {
        vector<int> memo(n+1, -1);
        return Solve(n, memo);
    }
};