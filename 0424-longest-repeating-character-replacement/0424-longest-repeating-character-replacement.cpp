class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l=0, r=0;
        unordered_map<char, int> mpp;
        int maxLen = 0, maxCnt = 0;
        while(r < n){
            mpp[s[r]]++;
            maxCnt = max(maxCnt, mpp[s[r]]);

            if((r-l+1) - maxCnt > k){
                mpp[s[l]]--;
                maxCnt = 0;
                for(auto [key, cnt]: mpp){
                    maxCnt = max(maxCnt, cnt);
                }

                l++;
            }

            if((r-l+1) - maxCnt <= k){
                maxLen = max(maxLen, r-l+1);
            }

            r++;
        }

        return maxLen;
    }
};