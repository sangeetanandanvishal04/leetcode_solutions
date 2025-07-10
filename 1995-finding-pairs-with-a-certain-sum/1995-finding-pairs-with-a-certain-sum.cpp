class FindSumPairs {
public:
    vector<int> arr2;
    unordered_map<int, int> mpp1, mpp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int num: nums1){
            mpp1[num]++;
        }

        arr2 = nums2;
        for(int num: nums2){
            mpp2[num]++;
        }
    }
    
    void add(int index, int val) {
        mpp2[arr2[index]]--;

        if(mpp2[arr2[index]] == 0){
            mpp2.erase(arr2[index]);
        }

        arr2[index] += val;
        mpp2[arr2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto &it: mpp1){
            int num = it.first;
            int cnt = it.second;

            int rem = tot - num;
            if(mpp2.find(rem) != mpp2.end()){
                ans += cnt*mpp2[rem];
            }
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */