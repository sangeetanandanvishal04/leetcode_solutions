class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+1, 0);
        
        for(auto it: bookings){
            diff[it[0]] += it[2];
            if(it[1] + 1 <= n){
                diff[it[1]+1] -= it[2];
            }    
        }

        vector<int> res(n, 0);
        int cur = 0;
        for(int i=1; i<=n; i++){
            cur += diff[i];
            res[i-1] = cur;
        }

        return res;
    }
};