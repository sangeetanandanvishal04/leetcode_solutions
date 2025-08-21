class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer(2);
        unordered_map<int, int> mpp1, mpp2;
        
        for(int num: nums1){
            mpp1[num]++;
        }
        for(int num: nums2){
            mpp2[num]++;
        }
        
        for(auto it: mpp1){
            if(mpp2.find(it.first) == mpp2.end()){
                answer[0].push_back(it.first);
            }    
        }

        for(auto it: mpp2){
            if(mpp1.find(it.first) == mpp1.end()){
                answer[1].push_back(it.first);
            }    
        }

        return answer;
    }
};