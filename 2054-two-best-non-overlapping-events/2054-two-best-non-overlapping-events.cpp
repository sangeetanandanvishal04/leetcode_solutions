class Solution {
private:
    int findNext(vector<vector<int>>& events, int startIdx, int endTime){
        int low = startIdx, high = events.size()-1;
        
        int ans = events.size();
        while(low <= high){
            int mid = low + (high-low)/2;

            if(events[mid][0] > endTime){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }   
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        int n = events.size();
        vector<int> suffixMax(n+1);
        suffixMax[n-1] = events[n-1][2];
        for(int i=n-2; i>=0; i--){
            suffixMax[i] = max(suffixMax[i+1], events[i][2]);
        }
        
        int maxVal = 0;
        for(int i=0; i<n; i++){
            maxVal = max(maxVal, events[i][2]);
            
            int nextIdx = findNext(events, i+1, events[i][1]);
            if(nextIdx < n){
                maxVal = max(maxVal, events[i][2] + suffixMax[nextIdx]);
            }
        }

        return maxVal;
    }
};