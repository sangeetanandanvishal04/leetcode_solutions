class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        int mod = 1e9 + 7;
        long long total = 0;
        long long ones = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                ones++;
            }
            else{
                long long x = (ones*(ones+1)) % mod;
                total += x / 2;
                ones = 0;
            }
        }

        if(ones != 0){
            total += (long long)(ones*(ones+1)) / 2;
        }

        return total;
    }
};