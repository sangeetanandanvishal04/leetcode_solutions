class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;
        int cnt = 0;

        for(auto d : dominoes){
            if(d[0] > d[1]){
                swap(d[0], d[1]);
            }   

            cnt += mp[make_pair(d[0], d[1])]++;
        }

        return cnt;
    }
};