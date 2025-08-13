class Solution {
private:
    bool checkPowerofThree(int n){
        if(n <= 0){
            return false;
        }
        if(n == 1){
            return true;
        }
        if(n % 3 == 0){
            n = n / 3;
            if(checkPowerofThree(n) == true){
                return true;
            }
        }
        return false;
    }    
public:
    bool isPowerOfThree(int n) {
        return checkPowerofThree(n);
    }
};