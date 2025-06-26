class Solution {
private:
    int f(int idx, int jumps, vector<int>& nums, vector<vector<int>>& memo, int n){
        if(idx >= n-1){
            return jumps;
        }

        if(memo[idx][jumps] != -1){
            return memo[idx][jumps];
        }

        int minJump = INT_MAX;
        for(int j=1; j<=nums[idx]; j++){
            minJump = min(minJump, f(idx+j, jumps+1, nums, memo, n));
        }

        return memo[idx][jumps] = minJump;
    }    
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        //vector<vector<int>> memo(n, vector<int>(n, -1));
        //return f(0, 0, nums, memo, n);

        int jumps=0, l=0, r=0;
        
        while(r < n-1){
            int end = 0;
            for(int j=l; j<=r; j++){
                end = max(end, j+nums[j]);
            }
            
            l = r+1;
            jumps++;
            r = end;
        }

        return jumps;
    }
};