class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int>st;

        for(int num: nums){
            if(num != 0){
                st.insert(num);
            }
        }

        return st.size();
    }
};