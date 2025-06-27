class Solution {
private:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int cnt = 0;
        int endTime = INT_MIN;

        for(auto interval: intervals){
            if(interval[0] >= endTime){
                endTime = interval[1];
                cnt++;
            }
        }

        return intervals.size()-cnt;
    }
};