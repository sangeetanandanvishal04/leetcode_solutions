class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0;
        int n = s.length();
        unordered_map<char, int> mpp; //{num, idx}
        
        int maxLen = 0;
        while(r < n){
            if(mpp.find(s[r]) != mpp.end()){
                l = max(l, mpp[s[r]]+1);
            }
            
            maxLen = max(maxLen, r-l+1);
            mpp[s[r]] = r;
            r++;
        }

        return maxLen;
    }
};