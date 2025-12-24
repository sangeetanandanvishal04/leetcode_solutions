class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long range = n*n;
        
        long long sn = (range*(range+1)) / 2;
        long long s = 0;
        long long s_sqn = (range*(range+1)*(2*range+1)) / 6;
        long long s_sq = 0;
        for(vector<int> vec: grid){
            for(int num: vec){
                s += num;
                s_sq += (long long)(num*num);
            }
        }

        long long eq1 = s - sn; // missing - repeating
        long long eq2 = (s_sq - s_sqn) / eq1; // missing + repeating

        int missing = (eq1 + eq2) / 2;
        int repeating = eq2 - missing;

        return {missing, repeating};
    }
};