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
        
        return majorityElement;
    }
};