class Solution {
private:
    bool isAdj(char a, char b){
        int d = abs(a-b);
        return d == 1 || d == 25;
    }
public:
    string resultingString(string s) {
        stack<char> st;
        for(char ch: s){
            if(!st.empty() && isAdj(st.top(), ch)){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};