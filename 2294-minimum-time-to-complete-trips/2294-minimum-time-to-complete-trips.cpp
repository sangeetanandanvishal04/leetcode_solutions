class Solution {
private:
    bool canPossible(vector<int>& time, int totalTrips, long long tm){
        long long cntTrips = 0;

        for(int t: time){
            cntTrips += (tm / t);
            if(cntTrips >= totalTrips){
                return true;
            }
        }

        return false;
    }    
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = *min_element(time.begin(), time.end());
        long long high = low * 1LL * totalTrips;

        while(low <= high){
            long long mid = low + (high - low)/2;
            if(canPossible(time, totalTrips, mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};