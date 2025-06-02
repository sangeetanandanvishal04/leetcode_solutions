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
        return Solve(nums, k) - Solve(nums, k-1);
    }
};