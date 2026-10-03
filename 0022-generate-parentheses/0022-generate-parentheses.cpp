class Solution {
private:
    void solve(int n,int open, int close, string current, vector<string>& result){
        if(current.length() == 2*n){
            result.push_back(current);
        }

        if(open < n){
            solve(n, open+1, close, current+'(', result);
        }
        if(close < open){
            solve(n, open, close+1, current+')', result);
        }
    }    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(n, 0, 0, "", result);
        return result;
    }
};