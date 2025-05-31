class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(int num: nums){
            int digit = 0;
            while(num > 0){
                digit++;
                num /= 10;
            }

            if(digit%2 == 0){
                res++;
            }
        }

        return res;
    }
};