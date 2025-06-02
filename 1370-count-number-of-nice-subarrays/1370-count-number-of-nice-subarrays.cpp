class Solution {
private:
    int Solve(vector<int>& nums, int k){
        int n = nums.size();
        int l=0, r=0;
        int niceCnt = 0, cnt = 0;

        while(r < n){
            if(nums[r]%2 != 0){
                cnt++;
            }

            while(cnt > k && l <= r){
                if(nums[l]%2 != 0){
                    cnt--;
                }
                l++;
            }

            if(cnt <= k){
                niceCnt += (r-l+1);
            }

            r++;
        }

        return niceCnt;
    }      
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //return Solve(nums, k) - Solve(nums, k-1);
        
        int n = nums.size();

        for(int i=0; i<n; i++){
            nums[i] %= 2;
        }

        unordered_map<int, int> mpp; //{sum : cnt}
        mpp[0] = 1;
        int cnt = 0, sum = 0;
        
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(mpp.find(sum-k) != mpp.end()){
                cnt += mpp[sum-k];
            }

            mpp[sum]++;
        }

        return cnt;
    }
};