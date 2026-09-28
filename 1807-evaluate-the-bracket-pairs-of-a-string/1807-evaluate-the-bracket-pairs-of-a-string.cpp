class Solution {   
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for(auto pair: knowledge){
            mpp[pair[0]] = pair[1];
        }

        int n = s.length();
        stack<int> st;
        string result = "";

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')' && !st.empty()){
                int start = st.top() + 1;
                st.pop();

                string key = s.substr(start, i-start);
                if(mpp.find(key) != mpp.end()){
                    result += mpp[key];
                }
                else{
                    result += '?';
                }
            }
            else if(st.empty()){
                result += s[i];
            }
        }

        return result;
    }
};