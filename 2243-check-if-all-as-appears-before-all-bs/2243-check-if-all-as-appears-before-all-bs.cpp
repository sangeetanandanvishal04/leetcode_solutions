class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int countA = 0;
        int countB = 0;
        for(int i=0; i<n; i++){
            if(s[i] == 'a' && countB != 0){
                return false;
            }
            else if(s[i] == 'a'){
                countA++;
            }
            else if(s[i] == 'b'){
                countB++;
            }
        }

        return true;
    }
};