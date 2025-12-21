class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int x: asteroids){
            if(x < 0){
                bool destroyed = false;
                while(!st.empty() && st.top() > 0){
                    int y = st.top();
                    st.pop();
                    
                    if(abs(x) == y){
                        destroyed = true;
                        break;
                    } 
                    
                    if(abs(x) < y){
                        destroyed = true;
                        st.push(y);
                        break;
                    }
                }
               
                if(destroyed == false){
                    st.push(x);
                } 
            }
            else{
                st.push(x);
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};