class Solution {  
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> hash(3, 0);
        int cnt = 0, l = 0, r = 0;

        while(r < n){
            hash[s[r]-'a']++;

            while(hash[0] > 0 && hash[1] > 0 && hash[2] > 0){
                cnt += (n - r);
                hash[s[l]-'a']--;
                l++;
            }
            
            r++;
        }

        return cnt;
    }
};