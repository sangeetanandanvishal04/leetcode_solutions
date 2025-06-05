class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> vec(128, 0);
        int n = s.length();
        int m = t.length();

        for(char ch: t){
            vec[ch]++;
        }

        int l=0, r=0, cnt=0, minLen=INT_MAX;
        int startIdx = -1;

        while(r < n){
            if(vec[s[r]] > 0){
                cnt++;
            }
            vec[s[r]]--;

            while(cnt == m){
                if(r-l+1 < minLen){
                    startIdx = l;
                    minLen = r-l+1;
                }

                vec[s[l]]++;
                if(vec[s[l]] > 0){
                    cnt--;
                }

                l++;
            }
        
            r++;
        }

        return startIdx == -1? "": s.substr(startIdx, minLen);
    }
};