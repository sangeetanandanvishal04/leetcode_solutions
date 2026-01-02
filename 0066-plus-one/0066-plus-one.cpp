class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        vector<int> result;
        int carry = 0;
        for(int i=n-1; i>=0; i--){
            int num = digits[i]+carry;
            if(i == n-1){
                num++;
            }

            carry = num/10;
            num %= 10;

            result.push_back(num);
        }

        if(carry > 0){
            result.push_back(carry);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
