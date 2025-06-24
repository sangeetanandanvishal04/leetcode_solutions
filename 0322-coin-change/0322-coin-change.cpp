class Solution {
private:
    int Solve(int idx, int target, vector<int>& coins, vector<vector<int>>& memo){
        if(idx == 0){
            if(target % coins[idx] == 0){
                return target / coins[idx];
            }
            return 1e9;
        }

        if(memo[idx][target] != -1){
            return memo[idx][target];
        }

        int notTake = Solve(idx-1, target, coins, memo);

        int take = 1e9;
        if(coins[idx] <= target){
            take = 1 + Solve(idx, target-coins[idx], coins, memo);
        }

        return memo[idx][target] = min(take, notTake);
    }    
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> memo(n, vector<int>(amount+1, -1));
        int ans = Solve(n-1, amount, coins, memo);

        return ans != 1e9? ans: -1;    
    }
};