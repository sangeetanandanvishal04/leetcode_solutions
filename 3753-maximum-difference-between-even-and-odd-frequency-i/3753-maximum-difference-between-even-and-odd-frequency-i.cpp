class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> vec;

        for(char ch: s){
            vec[ch]++;
        }

        int a1 = INT_MIN;
        int a2 = INT_MAX;

        for(auto [key, val]: vec){
            if(val%2 != 0){
                a1 = max(a1, val);
            }
            else{
                a2 = min(a2, val);
            }
        }

        return a1-a2;
    }
};