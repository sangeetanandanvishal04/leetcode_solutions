class Solution {
int perform(int a, char op, int b){
    if (op == '/') {
        return b == 0 ? 0 : a / b;
    } 
    else if (op == '*') {
        return a*b;
    }
    else if (op == '-') {
        return a-b;
    }
    else {
        return a+b;
    }
}

int precedence(char op) {
    if (op == '*' || op == '/') {
        return 2;
    } 
    else if (op == '+' || op == '-') {
        return 1;
    } 
    else {
        return 0;
    }
}

bool hasHigherPrecedence(char op1, char op2) {
    return precedence(op1) >= precedence(op2);
}    
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> operands;
        stack<char> operators;

        for(int i=0; i<n; i++){
            char ch = s[i];

            if(isdigit(ch)){
                int num = 0;
                while(i<n && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                i--; 
                operands.push(num);
            } 
            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                while(!operators.empty() && hasHigherPrecedence(operators.top(), ch)){
                    int b = operands.top();
                    operands.pop();
                    int a = operands.top();
                    operands.pop();
                    char op = operators.top();
                    operators.pop();
                    operands.push(perform(a, op, b));
                }

                operators.push(ch);
            }
        }

        while(!operators.empty()){
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            char op = operators.top();
            operators.pop();
            operands.push(perform(a, op, b));
        }

        return operands.top();
    }
};