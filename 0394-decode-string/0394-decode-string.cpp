class Solution {   
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        
        string curStr = "";
        int curNum = 0;
        
        for(char ch: s){
            if(isdigit(ch)){
                curNum = curNum*10 + (ch - '0');
            }
            else if(ch == '['){
                numStack.push(curNum);
                strStack.push(curStr);
                
                curNum = 0;
                curStr = "";
            }
            else if(ch == ']'){
                int k = numStack.top();
                numStack.pop();
                string prevMsg = strStack.top();
                strStack.pop();
                
                string expandedMsg = prevMsg;
                for(int i=0; i<k; i++){
                    expandedMsg += curStr;
                }
                curStr = expandedMsg;
            }
            else{
                curStr.push_back(ch);
            }
        }
        
        return curStr;  
    }
};