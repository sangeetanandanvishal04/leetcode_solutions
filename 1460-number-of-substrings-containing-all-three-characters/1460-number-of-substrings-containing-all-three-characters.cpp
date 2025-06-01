class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> hash(4, -1);
        int cnt = 0;

        for(int i=0; i<n; i++){
            hash[s[i]-'a'] = i;
            cnt += 1 + min(hash[0], min(hash[1], hash[2]));
        }

        return cnt;
    }
};