class Solution {
private:
    int F(int n, vector<int>& memo){
        if(n == 0 || n == 1){
            return n;
        }

        if(memo[n] != -1){
            return memo[n];
        }

        return memo[n] = F(n-1, memo) + F(n-2, memo);
    }    
public:
    int fib(int n) {
        //vector<int> memo(n+1, -1);
        //return F(n, memo);

        if(n == 0 || n == 1){
            return n;
        }

        int prev2 = 0;
        int prev1 = 1;

        for(int i=2; i<=n; i++){
            int cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};