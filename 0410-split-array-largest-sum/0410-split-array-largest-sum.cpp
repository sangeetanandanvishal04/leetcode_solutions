class Solution {
private:
    bool canWeSplit(vector<int>& nums, int k, int val){
        long long sum = 0;
        int cnt = 1;

        for(int num: nums){
            if(sum + num <= val){
                sum += num;
            }
            else{
                cnt++;
                sum = num;
            }
        }

        if(cnt <= k){
            return true;
        }
        return false;
    }    
public:
    int splitArray(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int low = maxi, high = sum;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(canWeSplit(nums, k, mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};