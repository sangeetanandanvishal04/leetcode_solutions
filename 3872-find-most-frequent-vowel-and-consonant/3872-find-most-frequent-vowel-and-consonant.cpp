class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26];
        int maxVowel = 0, maxConst = 0;

        for(char ch: s){
            freq[ch-'a']++;
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                maxVowel = max(maxVowel, freq[ch-'a']);
            }
            else{
                maxConst = max(maxConst, freq[ch-'a']);
            }
        }

        return maxVowel + maxConst;
    }
};