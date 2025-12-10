class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for(int num: nums){
            if(num > 0){
                st.insert(num);
            }
        }

        int missing = 1;
        while(st.find(missing) != st.end()){
            missing++;
        }
        
        return missing;
    }
};