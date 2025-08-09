class Solution {
private:
    bool checkPowerofFour(int n){
        if(n <= 0){
            return false;
        }
        if(n == 1){
            return true;
        }
        if(n%4 == 0){
            n = n/4;
            if(checkPowerofFour(n) == true){
                return true;
            }
        }
        
        return false;
    }    
public:
    bool isPowerOfFour(int n) {
        return checkPowerofFour(n);
    }
};