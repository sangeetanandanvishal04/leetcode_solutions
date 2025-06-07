class Solution {
private:
    long long Solve(int idx, int k, int state, vector<int>& prices, vector<vector<vector<long long>>>& memo){
        int n = prices.size();
        if(idx == n || k == 0){
            return (state == 0)? 0 : LLONG_MIN/2;
        }

        if(memo[idx][k][state] != -1){
            return memo[idx][k][state];
        }

        long long ans = Solve(idx+1, k, state, prices, memo);

        if(state == 0){
            ans = max(ans, -prices[idx] + Solve(idx+1, k, 1, prices, memo));

            ans = max(ans, prices[idx] + Solve(idx+1, k, 2, prices, memo));
        }
        else if(state == 1){
            ans = max(ans, prices[idx] + Solve(idx+1, k-1, 0, prices, memo));
        }
        else{
            ans = max(ans, -prices[idx] + Solve(idx+1, k-1, 0, prices, memo));
        }

        return memo[idx][k][state] = ans;
    }
    
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        
        vector<vector<vector<long long>>> memo(n, vector<vector<long long>>(k+1, vector<long long>(3, -1)));
        
        return Solve(0, k, 0, prices, memo);
    }
};