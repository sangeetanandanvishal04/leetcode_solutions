class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, cnt = 0;
        bool check = false;

        for(int i=0; i<n; i++){
            if(i == 0){
                check = true;
            }

            sum += nums[i];
            if(sum == 0 && check == true){
                cnt++;
            }
        }

        return cnt;
    }
};