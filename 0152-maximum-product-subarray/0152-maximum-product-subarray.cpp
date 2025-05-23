class Solution {    
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minProduct = nums[0];
        int maxProduct = nums[0];
        int globalMaxProduct = nums[0];

        for(int i=1; i<n; i++){
            int prevMax = maxProduct;
            int prevMin = minProduct;

            maxProduct = max(nums[i], max(prevMax*nums[i], prevMin*nums[i]));
            minProduct = min(nums[i], min(prevMax*nums[i], prevMin*nums[i]));

            globalMaxProduct = max(globalMaxProduct, maxProduct);
        }

        return globalMaxProduct;
    }
};