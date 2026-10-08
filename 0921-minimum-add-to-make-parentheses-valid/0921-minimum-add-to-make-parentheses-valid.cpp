class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, closed = 0;

        for(char ch: s){
            if(ch == '('){
                open++;
            }
            else{
                closed++;
                if(closed > 0 && open > 0){
                  open--;
                  closed--;
                } 
            }
        }

        return open + closed;
    }
};