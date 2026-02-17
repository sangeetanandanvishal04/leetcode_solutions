class Solution {
public:
    int minimumChairs(string s) {
        int current_occupancy = 0;
        int max_occupancy = 0;

        for(char ch: s){
            if(ch == 'E'){
                current_occupancy += 1;
            }
            else{
                current_occupancy -= 1;
            }

            max_occupancy = max(max_occupancy, current_occupancy);
        }

        return max_occupancy;
    }
};