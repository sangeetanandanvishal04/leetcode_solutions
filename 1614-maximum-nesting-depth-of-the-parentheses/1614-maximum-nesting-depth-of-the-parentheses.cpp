class Solution {
public:
    int maxDepth(string s) {
        int result = 0;

        stack<int> st;
        for(char ch: s){
            if(ch == '('){
                st.push(ch);
            }
            else if(ch == ')' && !st.empty()){
                int depth = st.size();
                result = max(depth, result);
                st.pop();
            }
        }

        return result;
    }
};