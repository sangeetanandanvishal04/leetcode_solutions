class Solution {
private:
    bool isPossible(int k, int n, int f){
        long long sum = 0;
        long long c = 1;
        for(int i=1; i<=k; i++){
            c = c*(f-i+1)/i;
            sum += c;

            if(sum >= n){
                return true;
            }
        }

        return false;
    }    
public:
    int superEggDrop(int k, int n) {
        int low = 0, high = n;

        while(low <= high){
            int midf = low + (high-low)/2;
            if(isPossible(k, n, midf)){
                high = midf-1;
            }
            else{
                low = midf+1;
            }
        }

        return low;
    }
};