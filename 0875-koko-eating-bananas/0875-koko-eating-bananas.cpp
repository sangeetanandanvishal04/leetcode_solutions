class Solution {
private:
    bool canEat(vector<int>& piles, int speed, int hours){
        long long h = 0;

        for(int pile: piles){
            h += ceil((double)pile / speed); 

            if(h > (long long)hours){
                return false;
            }   
        }

        return true;
    }    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for(int pile: piles){
            maxi = max(maxi, pile);
        }
        
        int low = 1, high = maxi;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(canEat(piles, mid, h) == true){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};