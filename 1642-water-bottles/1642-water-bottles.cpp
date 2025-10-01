class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int maxDrink = numBottles;
        int temp = numBottles / numExchange;
    
        while(temp > 0){
            maxDrink += temp;
            int empty = numBottles % numExchange;
            numBottles = temp+empty;
            temp = (numBottles / numExchange); 
        }

        return maxDrink;
    }
};