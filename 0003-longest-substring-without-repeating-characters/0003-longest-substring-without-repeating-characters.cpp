class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0, r = 0;
        int maxLen = 0;
        unordered_map<int, int> mp;

        while(r < n){
            if(mp.find(s[r]) != mp.end()){
                l = max(l, mp[s[r]] + 1);
            }

            maxLen = max(maxLen, r-l+1);
            mp[s[r]] = r;
            r++;
        }

        return maxLen;
    }
};