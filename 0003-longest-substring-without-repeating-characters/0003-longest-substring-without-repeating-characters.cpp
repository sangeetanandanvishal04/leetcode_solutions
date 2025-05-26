class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxCnt = 0, start = 0;
        unordered_map<char, int> mp;

        for(int i=0; i<n; i++){
            if(mp.find(s[i]) != mp.end()){
                start = max(start, mp[s[i]]+1);
            }

            maxCnt = max(maxCnt, i-start+1);
            mp[s[i]] = i;
        }

        return maxCnt;
    }
};