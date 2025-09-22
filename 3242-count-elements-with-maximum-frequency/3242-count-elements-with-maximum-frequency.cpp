class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int maxi = 0;
        for(int num: nums){
            mpp[num]++;
            maxi = max(maxi, mpp[num]);
        }
        
        int cnt = 0;
        for(auto it: mpp){
            if(it.second == maxi){
                cnt += maxi;
            }
        }

        return cnt;
    }
};