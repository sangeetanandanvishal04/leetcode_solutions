class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp; // {num, cnt};
        for(int num: arr){
            mpp[num]++;
        }

        unordered_set<int> st;
        for(auto [num, cnt]: mpp){
            if(st.find(cnt) != st.end()){
                return false;
            }

            st.insert(cnt);
        }

        return true;
    }
};