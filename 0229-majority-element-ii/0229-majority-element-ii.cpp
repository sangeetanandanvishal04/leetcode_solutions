class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majorityEle1 = 0, majorityEle2 = 0;
        int cnt1 = 0, cnt2 = 0;
        
        for(int num : nums) {
            if(majorityEle1 == num){
                cnt1++;
            }
            else if(majorityEle2 == num){
                cnt2++;
            }
            else if(cnt1 == 0){
                majorityEle1 = num;
                cnt1++;
            }
            else if(cnt2 == 0){
                majorityEle2 = num;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for(int num : nums) {
            if(majorityEle1 == num){
                cnt1++;
            }
            else if(majorityEle2 == num){
                cnt2++;
            }
        }
        
        vector<int> result;
        if(cnt1 > n/3){
            result.push_back(majorityEle1);
        }
        if(cnt2 > n/3){
            result.push_back(majorityEle2);
        }

        return result;
    }
};