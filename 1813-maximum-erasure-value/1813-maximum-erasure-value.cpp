class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN, cur = 0;
        int l = 0, r = 0;
        unordered_set<int> st;
        while(r < n){
            while(st.find(nums[r]) != st.end()){
                st.erase(nums[l]);
                cur -= nums[l];
                l++;
            }

            st.insert(nums[r]);
            cur += nums[r];
            maxi = max(maxi, cur);
            r++;
        }

        return maxi;
    }
};