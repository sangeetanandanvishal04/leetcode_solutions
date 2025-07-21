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
        for(int f=0; f<=n; f++){
            if(isPossible(n, f)){
                return f;
            }
        }

        return n;
    }
};