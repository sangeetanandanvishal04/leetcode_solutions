class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long cost = 0;

        if(n > k){
            cost += 1LL*k*(n-k);
        }
        if(m > k){
            cost += 1LL*k*(m-k);
        }

        return cost;
    }
};