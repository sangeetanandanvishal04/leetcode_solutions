class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                break;
            }
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            
            int low = i+1, high = n-1;
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];

                if(sum == 0){
                    result.push_back({nums[i], nums[low], nums[high]});
                    low++;

                    while(nums[low] == nums[low-1] && low<high){
                        low++;
                    }
                }
                else if(sum < 0){
                    low++;
                }
                else{
                    high--;
                }
            }
        }

        return result;
    }
};