class Solution {
private:
    int solve(string& str, char a, char b, int points){
        stack<char> st;
        int total_points = 0;

        for(char ch : str){
            if(!st.empty() && st.top() == a && ch == b){
                st.pop();
                total_points += points;
            } 
            else {
                st.push(ch);
            }
        }

        string remaining;
        while(!st.empty()){
            remaining += st.top();
            st.pop();
        }

        reverse(remaining.begin(), remaining.end());
        str = remaining;
        return total_points;
    }    
public:
    int maximumGain(string s, int x, int y) {
        char first_char, second_char;
        int first_points, second_points;
        
        if(x > y){
            first_char = 'a';
            second_char = 'b';
            first_points = x;
            second_points = y;
        } 
        else {
            first_char = 'b';
            second_char = 'a';
            first_points = y;
            second_points = x;
        }

        int result = solve(s, first_char, second_char, first_points);
        result += solve(s, second_char, first_char, second_points);
        return result; 
    }
};