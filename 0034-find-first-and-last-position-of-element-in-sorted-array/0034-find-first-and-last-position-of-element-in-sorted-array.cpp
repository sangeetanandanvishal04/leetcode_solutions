class Solution {
private:
    int upperBound(vector<int>& nums, int low, int high, int target){
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }

    int lowerBound(vector<int>& nums, int low, int high, int target){
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] >= target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int firstIdx = lowerBound(nums, 0, n-1, target);
        if(firstIdx == n || nums[firstIdx] != target){
            return {-1, -1};
        }

        int lastIdx = upperBound(nums, firstIdx, n-1, target);
        return {firstIdx, lastIdx-1};
    }
};