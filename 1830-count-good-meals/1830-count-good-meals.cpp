class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int n = deliciousness.size();
        const int MOD = 1e9 + 7;
        unordered_map<int, int> mp;
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<=21; j++){
                int powerOfTwo = 1 << j;

                if(mp.find(powerOfTwo-deliciousness[i]) != mp.end()){
                    count = (count + mp[powerOfTwo-deliciousness[i]]) % MOD;
                }
            }

            mp[deliciousness[i]]++;
        }

        return count;
    }
};