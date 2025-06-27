class Solution {
private:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }    
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), comp);

        int m = meetings.size();

        vector<long long> endTime(n, 0);
        vector<int> trackCnt(n, 0);
        int ansRoom = 0;
        long long maxCnt = 0;

        for(int i=0; i<m; i++){
            long long startTime = meetings[i][0];
            long long duration = meetings[i][1] - meetings[i][0];
            int room = -1;

            for(int j=0; j<n; j++){
                if(endTime[j] == 0 || endTime[j] <= startTime){
                    room = j;
                    break;
                }
            }

            if(room == -1){
                room = min_element(endTime.begin(), endTime.end())-endTime.begin();
                startTime = endTime[room];
            }
            
            endTime[room] = startTime + duration;
            trackCnt[room]++;

            if(trackCnt[room] > maxCnt ||
                (trackCnt[room] == maxCnt && room < ansRoom)){
                maxCnt = trackCnt[room];
                ansRoom = room;
            }

        }

        return ansRoom;
    }
};