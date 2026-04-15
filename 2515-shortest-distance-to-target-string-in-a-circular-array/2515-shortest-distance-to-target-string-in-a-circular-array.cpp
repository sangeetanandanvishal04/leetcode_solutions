class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();

        for(int steps=0; steps<n; steps++){
            int r = (startIndex + steps) % n;
            int l = (startIndex - steps + n) % n;

            if(words[l] == target || words[r] == target){
                return steps;
            }
        }

        return -1;
    }
};