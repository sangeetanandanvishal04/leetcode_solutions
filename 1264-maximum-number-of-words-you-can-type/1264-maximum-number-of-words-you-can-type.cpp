class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<int, int> mp;
        for(char ch: brokenLetters){
            mp[ch]++;
        }
        int n = text.size();
        int cnt = 0, total = 1;
        bool isNew = true;

        for(int i=0; i<n; i++){
            if(text[i] == ' '){
                total++;
                isNew = true;
            }
            else if(isNew && mp.find(text[i]) != mp.end()){
                cnt++;
                isNew = false;
            }
        }

        return total-cnt;
    }
};