class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int alice1 = 0, alice2 = 0;

        for(int num: nums){
            int digit = 0;
            int x = num;
            while(num > 0){
                digit++;
                num /= 10;
            }

            if(digit == 1){
                alice1 += x;
            } 
            if(digit == 2){
                alice2 += x;
            }
        }

        return (max(alice1, alice2) - min(alice1, alice2)) > 0;
    }
};