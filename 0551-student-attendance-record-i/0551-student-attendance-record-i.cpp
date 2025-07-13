class Solution {
public:
    bool checkRecord(string s) {
        int cntA = 0, cntL = 0;

        for(char ch: s){
            if(ch == 'A'){
                cntA++;
                if(cntA >= 2){
                    return false;
                }
                cntL = 0;
            }
            else if(ch == 'L'){
                cntL++;
                if(cntL >= 3){
                    return false;
                }
            }
            else{
                cntL = 0;
            }
        }

        return true;
    }
};