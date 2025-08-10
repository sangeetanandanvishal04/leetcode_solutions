class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixAND; //{num, cnt}
        int n = nums.size();
        long long count = 0;

        for(int num: nums){
            unordered_map<int, int> currentAND; //{num, cnt}
            for(auto [key, cnt]: prefixAND){
                currentAND[key & num] += cnt;
            }

            currentAND[num]++;
            count += currentAND[k];
            prefixAND = currentAND;
        }

        return count;
    }
};