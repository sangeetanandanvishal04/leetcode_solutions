class Solution {
private:
    bool isDigit(char ch){
        return ch >= '0' && ch <= '9';
    }
public:
    int calculate(string s){
        stack<long long> operands;
        stack<long long> operators;
        long long sum = 0;
        long long sign = 1;  
        
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            
            if(ch == ' '){
                continue;
            } 
            else if(isDigit(ch)){
                long long num = 0;
                while(i<s.size() && isDigit(s[i])){
                    num = num*10 + (s[i] - '0');
                    i++;
                }
                i--;  
                sum += num*sign;
                sign = 1;  
            } 
            else if(ch == '+'){
                sign = 1;
            } 
            else if(ch == '-'){
                sign = -1;
            } 
            else if(ch == '('){
                operands.push(sum);
                operators.push(sign);
                sum = 0;
                sign = 1;
            } 
            else if(ch == ')'){
                sum = operands.top() + operators.top()*sum;
                operands.pop();
                operators.pop();
            }
        }
        
        return (int)sum;
    }
};