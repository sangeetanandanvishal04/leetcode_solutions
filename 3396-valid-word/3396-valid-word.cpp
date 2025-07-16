class Solution {
private:
    bool Check(char ch){
        return (ch >= '0' && ch <='9') || 
               (ch >= 'a' && ch <='z');
    } 

    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }  

    bool isConsonent(char ch){
        return (ch >= 'a' && ch <= 'z') && !isVowel(ch);
    } 
public:
    bool isValid(string word) {
        int n = word.length();
        if(n < 3){
            return false;
        }
        
        int cntV = 0, cntC = 0;
        for(char ch: word){
            if(!Check(tolower(ch))){
                return false;
            }
            if(isVowel(tolower(ch))){
                cntV++;
            }
            else if(isConsonent(tolower(ch))){
                cntC++;
            }
        }

        return cntV > 0 && cntC > 0;
    }
};