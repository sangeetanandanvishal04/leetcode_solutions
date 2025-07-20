class Solution {  
private:
    bool isPossible(vector<int>& nums, int k, int cap){
        int n = nums.size();
        int i = 0, cnt = 0;
        while(i<n){
            if(nums[i] <= cap){
                cnt++;
                i += 2;
            }
            else{
                i += 1;
            }
        }

        return cnt >= k;
    }    
public:
    int minCapability(vector<int>& nums, int k) {
        int left = INT_MAX;
        int right = INT_MIN;

        for(int num: nums){
            left = min(left, num);
            right = max(right, num);
        }

        while(left <= right){
            int mid = left + (right-left)/2;

            if(isPossible(nums, k, mid)){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        return left;
    }
};