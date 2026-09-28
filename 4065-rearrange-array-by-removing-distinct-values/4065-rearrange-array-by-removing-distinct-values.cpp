class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int, int> mpp;

        for(auto num: nums){
            mpp[num]++;
        }

        vector<int> ans;
        ans.reserve(nums.size());

        while(ans.size() < nums.size()){
            for(auto& [key, val]: mpp){
                if(val > 0){
                    ans.push_back(key);
                    val--;
                }
            }
        }

        return ans;
    }
};