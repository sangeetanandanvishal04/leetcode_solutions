class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        char ans = keysPressed[0];
        int dur = releaseTimes[0];

        for(int i=1; i<n; i++){
            int d = releaseTimes[i] - releaseTimes[i-1];
            if(d > dur){
                dur = d;
                ans = keysPressed[i];
            }
            else if(d == dur && keysPressed[i] > ans){
                ans = keysPressed[i];
            }
        }

        return ans;
    }
};