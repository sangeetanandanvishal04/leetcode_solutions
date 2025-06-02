class Solution {
private:
    int Solve(vector<int>& nums, int goal){
        int n = nums.size();
        int l=0, r=0;
        int cnt = 0, sum = 0;

        while(r < n){
            sum += nums[r];
            while(sum > goal && l <= r){
                sum -= nums[l];
                l++;
            }
            if(sum <= goal){
                cnt += (r-l+1);
            }
            r++;
        }

        return cnt;
    }    
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //return Solve(nums, goal) - Solve(nums, goal-1);

        unordered_map<int, int> mpp; //{sum : cnt}
        mpp[0] = 1;
        int n = nums.size();
        int cnt = 0, sum = 0;
        
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(mpp.find(sum-goal) != mpp.end()){
                cnt += mpp[sum-goal];
            }

            mpp[sum]++;
        }

        return cnt;
    }
};