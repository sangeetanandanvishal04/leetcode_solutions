class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<pair<int, int>> answerIdx; // {openIdx, closedIdx}
        int start = 0, open = 0, closed = 0;
        int n = s.length();

        for(int i=0; i<n; i++){
            if(open == 0 && closed == 0){
                start = i;
            }

            if(s[i] == '('){
                open++;
            }
            else{
                closed++;
                if(open > 0 && closed > 0){
                    open--;
                    closed--;
                    if(open == 0 && closed == 0){
                        answerIdx.push_back({start+1, i-1});
                    }
                }
            }
        }

        string ans = "";
        for(pair<int, int> p: answerIdx){
            ans += s.substr(p.first, p.second-p.first+1);
        }

        return ans;
    }
};