class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        vector<int> result;

        for(int num: nums1) {
            mpp[num]++;
        }

        for(int num: nums2){
            if(mpp.find(num) != mpp.end()){
                result.push_back(num);
                mpp.erase(num);
            }
        }
        
        return result;
    }
};