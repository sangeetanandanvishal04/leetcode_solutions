class Solution {
private:
    int Solve(int idx, int prev, int modVal, vector<int>& nums, vector<vector<vector<int>>>& memo){
        if(idx < 0){
            return 0;
        }

        if(memo[idx][prev+1][modVal+1] != -1){
            return memo[idx][prev+1][modVal+1];
        }
        
        int ans = Solve(idx-1, prev, modVal, nums, memo);

        if(prev == -1){
            ans = max(ans, 1 + Solve(idx-1, idx, -1, nums, memo));
        }
        else{
            int curMod = (nums[idx] + nums[prev]) % 2;
            if(modVal == -1 || curMod == modVal){
                int nextMod = (modVal == -1)? curMod: modVal;
                ans = max(ans, 1 + Solve(idx-1, idx, nextMod, nums, memo));
            }
        }

        return memo[idx][prev+1][modVal+1] = ans;
    }    
public:
    int maximumLength(vector<int>& nums) {
        //int n = nums.size();
        //vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(n+2, vector<int>(3, -1)));
        //return Solve(n-1, -1, -1, nums, memo);

        int n = nums.size();
        
        int cntEven = 0, cntOdd = 0;
        for(int num: nums){
            if(num & 1){
                cntOdd++;
            }
            else{
                cntEven++;
            }
        }

        int evenSum = max(cntEven, cntOdd);
        int oddSum = 1;
        for(int i=1; i<n; i++){
            if((nums[i] & 1) != (nums[i-1] & 1)){
                oddSum++;
            }
        }

        return max(evenSum, oddSum);
    }
};