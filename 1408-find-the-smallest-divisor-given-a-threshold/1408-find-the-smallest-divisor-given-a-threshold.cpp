class Solution {
private:
    bool isPossible(vector<int>& nums, int threshold, int div){
        int sum = 0;
        for(int num: nums){
            sum += ceil((double)num / (double)div);
        }

        if(sum <= threshold){
            return true;
        }
        return false;
    }    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxDivisor = *max_element(nums.begin(), nums.end());

        int low = 1, high = maxDivisor;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(nums, threshold, mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};