class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word = "";
        for(char ch: s){
            if(ch == ' '){
                words.push_back(word);
                word = "";
            }
            else{
                word.push_back(ch);
            }
        }

        words.push_back(word);

        if(words.size() != pattern.length()){
            return false;
        }

        unordered_map<string, char> s2c;
        unordered_map<char, string> c2s;
        int n = pattern.length();

        for(int i=0; i<n; i++){
            char ch = pattern[i];
            string word = words[i];

            if(c2s.find(ch) != c2s.end()){
                if(c2s[ch] != word){
                    return false;
                }
            }
            else if(s2c.find(word) != s2c.end()){
                return false;
            }
            else{
                c2s[ch] = word;
                s2c[word] = ch;
            }
        }

        return true;
    }
};