class Solution {
private: 
    string expandAroundCenter(string s, int l, int r, int n){
        while(l>=0 && r<n && s[l] == s[r]){
            l--;
            r++;
        }

        return s.substr(l+1, r-l-1);
    }    
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string result = "";

        for(int i=0; i<n; i++){
            string even = expandAroundCenter(s, i, i+1, n); 
            if(even.length() > result.length()){
                result = even;
            }

            string odd = expandAroundCenter(s, i, i, n);
            if(odd.length() > result.length()){
                result = odd;
            }
        }

        return result;
    }
};