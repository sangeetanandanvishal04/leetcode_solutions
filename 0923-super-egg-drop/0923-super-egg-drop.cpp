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
        for(int f=0; f<=n; f++){
            if(isPossible(k, n, f)){
                return f;
            }
        }

        return n;
    }
};