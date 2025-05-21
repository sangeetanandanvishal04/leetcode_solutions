class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int,int>> sorted;
        for(int i=0; i<n; i++){
            sorted.push_back({nums[i], cost[i]});
        }
        
        sort(sorted.begin(), sorted.end(), [](auto &a, auto &b){return a.first < b.first;});

        long long totalW = 0;
        for(int cst: cost){
            totalW += cst;
        }

        long long halfW = (totalW + 1) / 2;
        
        long long curW = 0;                  
        int  medValue = 0;
        for(auto [num, cst]: sorted){
            curW += cst;
            if(curW >= halfW){
                medValue = num;
                break;
            }
        }
        
        long long min_cost = 0;
        for(auto [num, cst]: sorted){
            long long diff = llabs((long long)medValue - num);
            min_cost += diff * cst;
        }

        return min_cost;
    }
};