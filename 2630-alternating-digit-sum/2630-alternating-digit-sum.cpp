class Solution {
private:
    static int reverse(int n){
        int rev = 0;
        while(n > 0){
            int rem = n % 10;
            rev = (rev * 10) + rem;
            n /= 10;
        }

        return rev;
    }    
public:
    int alternateDigitSum(int n) {
        n = reverse(n);
        int sum = 0;
        bool flag = true;

        while(n > 0){
            int digit = n%10;
            n /= 10;
            if(flag){
                sum += digit;
                flag = false;
            }
            else{
                sum -= digit;
                flag = true;
            }
        }

        return sum;
    }
};