class Solution {
private:
    long long BIN(long long m) {
        if(m < 2){
            return 0;
        }    
        return (m*(m-1))/2;
    }    
public:
    long long distributeCandies(int n, int L) {
        long long T0 = n+2;
        long long T1 = n-L+1;  
        long long T2 = n-2*L;     
        long long T3 = n-3*L-1; 

        long long B0 = BIN(T0);
        long long B1 = BIN(T1);
        long long B2 = BIN(T2);
        long long B3 = BIN(T3);

        long long answer = B0 - 3*B1 + 3*B2 - B3;

        return answer;
    }
};