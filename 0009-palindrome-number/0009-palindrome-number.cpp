class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        
        long long rev = 0;
        int orig_x = x;

        while(x != 0){
            int lastDigit = x % 10;
            x = x/10;
            
            rev = rev*10 + lastDigit;
        } 

        return orig_x == rev;
    }
};