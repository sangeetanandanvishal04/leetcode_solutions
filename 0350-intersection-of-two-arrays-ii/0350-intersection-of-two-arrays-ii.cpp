class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        vector<int> result;

        for(int num : nums1) {
            mpp[num]++;
        }

        for(int num: nums2){
            if(mpp.find(num) != mpp.end()){
                result.push_back(num);
                mpp[num]--;
                if(mpp[num] == 0){
                    mpp.erase(num);
                }
            }
        }
        
        return result;
    }
};