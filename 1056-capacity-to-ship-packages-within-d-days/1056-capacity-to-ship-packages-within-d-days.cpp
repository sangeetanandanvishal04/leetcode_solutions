class Solution {
private:
    bool isPossible(vector<int>& weights, int days, int cap){
        int numDays = 1;
        int sum = 0;
        for(int w: weights){
            if(sum + w <= cap){
                sum += w;
            }
            else{
                numDays++;
                sum = w;
            }

            if(numDays > days){
                return false;
            }
        }

        if(numDays <= days){
            return true;
        }
        return false;
    }    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minCap = *max_element(weights.begin(), weights.end());
        int maxCap = accumulate(weights.begin(), weights.end(), 0);

        int low = minCap, high = maxCap;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(weights, days, mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};