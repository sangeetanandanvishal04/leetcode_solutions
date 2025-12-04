class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mpp;
        int n = s.length();
        int m = t.length();

        if(n != m){
            return false;
        }

        for(char ch: s){
            mpp[ch]++;
        }

        for(char ch: t){
            if(mpp.find(ch) == mpp.end()){
                return false;
            }

            mpp[ch]--;
            if(mpp[ch] == 0){
                mpp.erase(ch);
            }
        }

        return mpp.size() == 0;
    }
};