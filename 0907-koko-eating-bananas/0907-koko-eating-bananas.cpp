class Solution {
private:
    long long calHours(vector<int>& piles, int speed){
        long long hours = 0;
        for(int pile: piles){
            hours += ceil((double)pile / speed);
        }

        return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxSpeed = INT_MIN;
        for(int pile: piles){
            maxSpeed = max(maxSpeed, pile);
        }

        int low = 1, high = maxSpeed;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long reqTime = calHours(piles, mid);

            if(reqTime <= (long long)h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};