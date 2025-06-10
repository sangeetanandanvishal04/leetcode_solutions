class Solution {
public:
    int maxDifference(string s) {
        unordered_map<int, int> mpp;
        for(char ch: s){
            mpp[ch]++;
        }

        int a1 = INT_MIN;
        int a2 = INT_MAX;
        for(auto [key, val]: mpp){
            if(val%2 == 0){
                a2 = min(a2, val);
            }
            else{
                a1 = max(a1, val);
            }
        }

        return a1-a2;
    }
};