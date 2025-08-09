class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElement;
        int cnt = 0;
        
        for(int num : nums) {
            if(cnt == 0){
                majorityElement = num;
            }

            if(majorityElement == num){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        int cnt2 = 0;
        int n = nums.size();
        for(int num: nums){
            if(majorityElement == num){
                cnt2++;
                if(cnt2 > (n/2)){
                    return majorityElement;
                }
            }
        }
        
        return -1;
    }
};