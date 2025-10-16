class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int, int> mpp; //{num%value, cnt}

        for(int i=0; i<n; i++){
            int rem = ((nums[i] % value) + value) % value;
            mpp[rem]++;
        }

        int missing = 0;
        while(mpp[missing % value] > 0){
            mpp[missing % value]--;
            missing++;
        }

        return missing;
    }
};