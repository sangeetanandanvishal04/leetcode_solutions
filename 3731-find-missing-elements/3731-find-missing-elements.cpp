class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int num: nums){
            mini = min(mini, num);
            maxi = max(maxi, num);
            st.insert(num);
        }
        
        vector<int> result;
        for(int i=mini; i<= maxi; i++){
            if(st.find(i) == st.end()){
                result.push_back(i);
            }
        }

        return result;
    }
};