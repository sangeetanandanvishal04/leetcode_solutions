class Solution {
public:
    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        
        int low = 1, high = x;

        while(low <= high){
            int mid = low + (high - low)/2;
            long long sq = (long long)mid*(long long)mid;
            if(sq <= x*1LL){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return high;
    }
};