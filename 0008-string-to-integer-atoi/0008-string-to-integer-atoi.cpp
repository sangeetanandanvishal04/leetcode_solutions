class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i=0, sign = 1;
        while(i<n && s[i] == ' '){
            i++;
        }
        
        if(i == n){
            return 0;
        }
        
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
        
        long long num = 0;
        while(i < n && isdigit(s[i])){
            num = num*10 + (s[i] - '0');
            if(sign*num >= INT_MAX){
                return INT_MAX;
            }
            if(sign*num <= INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        
        return sign*(int)num;
    }
};