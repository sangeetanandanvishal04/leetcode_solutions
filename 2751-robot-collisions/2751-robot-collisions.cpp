class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        
        for(int i=0; i<n; i++){
            idx[i] = i;
        }

        sort(idx.begin(), idx.end(), [&](int a, int b){
            return positions[a] < positions[b];
        });

        stack<int> st; 
        vector<int> result;

        for(int i=0; i<n; i++){
            int robotIdx = idx[i];
            if(directions[robotIdx] == 'R'){
                st.push(robotIdx);
            } 
            else{
                while(!st.empty() && healths[robotIdx] > 0){
                    int topIdx = st.top();
                    if(healths[topIdx] == healths[robotIdx]){
                        st.pop();
                        healths[topIdx] = 0;
                        healths[robotIdx] = 0;
                    } 
                    else if(healths[topIdx] > healths[robotIdx]){
                        healths[topIdx] -= 1;
                        healths[robotIdx] = 0;
                    } 
                    else{
                        st.pop();
                        healths[robotIdx] -= 1;
                        healths[topIdx] = 0;
                    }
                }
                if(healths[robotIdx] > 0){
                    result.push_back(robotIdx);
                }
            }
        }

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        sort(result.begin(), result.end());
        vector<int> finalHealths;
        for(int i : result){
            if(healths[i] > 0){
                finalHealths.push_back(healths[i]);
            }
        }
        return finalHealths;
    }
};