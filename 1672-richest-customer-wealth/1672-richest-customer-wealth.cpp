class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int rich = 0;
        for(auto account : accounts) {
            int sum = 0;
            for(int money : account){
                sum += money;
            }

            rich = max(rich, sum);
        }
        
        return rich;
    }
};