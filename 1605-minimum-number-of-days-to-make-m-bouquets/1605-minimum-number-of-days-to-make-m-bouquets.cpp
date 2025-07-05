class Solution { 
private:
    bool canMake(vector<int>& bloomDay, int day, int m, int k){
        int n = bloomDay.size();

        int cnt = 0, numBonq = 0;
        for(int i=0; i<n; i++){
            if(bloomDay[i] <= day){
                cnt++;
                if(cnt == k){
                    numBonq++;
                    cnt = 0;
                }
            }
            else{
                cnt = 0;
            }
        }

        if(numBonq >= m){
            return true;
        }
        return false;
    }     
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = m*1LL*k*1LL;
        if(n < val){
            return -1;
        }

        int maxDays = *max_element(bloomDay.begin(), bloomDay.end());
        int minDays = *min_element(bloomDay.begin(), bloomDay.end());

        int low = minDays, high = maxDays;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(canMake(bloomDay, mid, m, k)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};