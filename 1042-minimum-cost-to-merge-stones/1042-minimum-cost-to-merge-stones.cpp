class Solution {
private:
    int Solve(int i, int j, vector<int>& stones, int piles, vector<int>& prefixSum, vector<vector<int>>& memo){ 
        if(i == j){
            return 0;
        }

        if(memo[i][j] != -1){
            return memo[i][j];
        }
        
        int mini = INT_MAX;
        for(int k=i; k<j; k+=(piles-1)){
            int temp = Solve(i, k, stones, piles, prefixSum, memo) + Solve(k+1, j, stones, piles, prefixSum, memo);  
            mini = min(mini, temp);
        }

        if((j-i) % (piles-1) == 0){
            mini += prefixSum[j+1] - prefixSum[i];
        }

        return memo[i][j] = mini;
    }    
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();

        if((n-1) % (k-1) != 0){
            return -1;
        }

        vector<int> prefixSum(n+1, 0);

        for(int i=0; i<n; i++){
            prefixSum[i+1] = prefixSum[i] + stones[i];
        }

        vector<vector<int>> memo(n, vector<int>(n, -1));
        return Solve(0, n-1, stones, k, prefixSum, memo);
    }
};