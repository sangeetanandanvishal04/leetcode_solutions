class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProduct(n);
        vector<int> suffixProduct(n);
        prefixProduct[0] = 1;
        suffixProduct[n-1] = 1;

        for(int i=1; i<n; i++){
            prefixProduct[i] = prefixProduct[i-1]*nums[i-1];
            suffixProduct[n-i-1] = suffixProduct[n-i]*nums[n-i];
        }
    
        vector<int> result;
        for(int i=0; i<n; i++){
            result.push_back(prefixProduct[i]*suffixProduct[i]);
        }   
           
        return result;
    }
};