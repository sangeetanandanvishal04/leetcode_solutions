class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int func = 0, sum = 0;
        
        for(int i=0; i<n; i++){
            sum += nums[i];
            func += i*nums[i];
        }

        int maxFunc = func;
        for(int k=1; k<n; k++){
            func = func + sum - n*nums[n-k];
            maxFunc = max(maxFunc, func);
        }

        return maxFunc;
    }
};