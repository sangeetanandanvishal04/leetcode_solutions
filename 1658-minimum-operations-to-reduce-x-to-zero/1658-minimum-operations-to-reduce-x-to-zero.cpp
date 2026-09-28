class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        
        int target = total - x;
        if(target < 0){
            return -1;
        }    
        if(target == 0){
            return n;
        }    

        int left = 0, right = 0;
        int sum = 0;
        int len = -1;

        while(right < n){
            sum += nums[right];

            while(left <= right && sum > target){
                sum -= nums[left];
                left++;
            }
            if(sum == target){
                len = max(len, right-left+1);
            }
            right++;
        }

        if(len == -1){
            return -1;
        }
        return n-len;
    }
};