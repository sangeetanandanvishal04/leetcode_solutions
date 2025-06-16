class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int steps = 0;
        while((maxDoubles > 0) && (target > 1)){
            if(target % 2 == 0){
                steps++;
                maxDoubles--;
                target /= 2; 
            }
            else{
                target--;
                steps++;
            }
        }

        return steps + target - 1;
    }
};