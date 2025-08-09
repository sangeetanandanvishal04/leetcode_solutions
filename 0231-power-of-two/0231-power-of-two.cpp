class Solution {
private:
    bool checkPowerOfTwo(int n){
        if(n <= 0){
            return false;
        }
        if(n == 1){
            return true;
        }
        if(n%2 == 0){
            n = n/2;
            if(checkPowerOfTwo(n) == true){
                return true;
            }
        }
        
        return false;
    }    
public:
    bool isPowerOfTwo(int n) {
        return checkPowerOfTwo(n);
    }
};