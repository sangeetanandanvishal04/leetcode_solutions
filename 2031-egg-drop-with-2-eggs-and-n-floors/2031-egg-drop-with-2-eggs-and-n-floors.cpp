class Solution {
private:
    bool isPossible(int n, int f){
        int sum = 0;
        int c = 1;

        for(int i=1; i<=2; i++){
            c = c*(f-i+1) / i;
            sum += c;
            if(sum >= n){
                return true;
            }
        }

        return false;
    }
public:
    int twoEggDrop(int n) {
        int low = 0, high = n;

        while(low <= high){
            int midf = low + (high-low)/2;
            if(isPossible(n, midf)){
                high = midf-1;
            }
            else{
                low = midf+1;
            }
        }

        return low;
    }
};