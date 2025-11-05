class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        unordered_map<int, int> mpp; //{num ->nge}
        stack<int> st;

        for(int i=n2-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            if(!st.empty()){
                mpp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        vector<int> ans(n1, -1);
        for(int i=0; i<n1; i++){
            if(mpp.find(nums1[i]) != mpp.end()){
                ans[i] = mpp[nums1[i]];
            }
        }

        return ans;
    }
};