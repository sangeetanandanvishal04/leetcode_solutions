class Solution {
private:
    long long Solve(int idx, vector<pair<int, int>>& nums, vector<long long>& memo){
        if(idx < 0){
            return 0;
        }

        if(memo[idx] != -1){
            return memo[idx];
        }

        long long notTake = Solve(idx-1, nums, memo);
        
        int j = idx-1;
        while(j >= 0){
            if(nums[j].first != nums[idx].first-1 && nums[j].first != nums[idx].first-2){
                break;
            }
            j--;
        } 

        long long take = 1LL*nums[idx].first * nums[idx].second + Solve(j, nums, memo);

        return memo[idx] = max(take, notTake);
    }    
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> mpp;
        for(int num: power){
            mpp[num]++;
        }

        vector<pair<int, int>> nums; //{num: cnt}
        for(auto it: mpp){
            nums.push_back({it.first, it.second});
        }

        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<long long> memo(n, -1);
        return Solve(n-1, nums, memo);
    }
};