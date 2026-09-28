class Solution {
private:
    void reverse(string& str, int l, int r){
        if(l < 0 || r>=str.length() || l > r){
            return;
        }
        
        while(l<r){
            char ch = str[l];
            str[l] = str[r];
            str[r] = ch;
 
            l++;
            r--;
        }
    }    
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int start = st.top()+1;
                st.pop();
                reverse(s, start, i-1);
            }
        }

        string result = "";
        for(char ch: s){
            if(ch == '(' || ch == ')'){
                continue;
            }
            else{
                result += ch;
            }
        }
        
        return result;
    }
};