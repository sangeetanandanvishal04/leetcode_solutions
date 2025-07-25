class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int sum = 0, maxEle = INT_MIN;

        for(int num: nums){
            maxEle = max(maxEle, num);
            if(num >= 0 && st.find(num) == st.end()){
                sum += num;
                st.insert(num);
            }
        }

        return sum > 0? sum: maxEle;
    }
};