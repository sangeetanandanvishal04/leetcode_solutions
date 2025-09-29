class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, max(trips[i][1], trips[i][2]));
        }
        
        vector<int> diff(maxi+1, 0);
        for(int i=0; i<n; i++){
            diff[trips[i][1]] += trips[i][0];
            diff[trips[i][2]] -= trips[i][0];   
        }
        
        int filled = 0;
        for(int i=0; i <= maxi; i++){
            filled += diff[i];
            if(filled > capacity){
                return false;
            }    
        }

        return true;
    }
};