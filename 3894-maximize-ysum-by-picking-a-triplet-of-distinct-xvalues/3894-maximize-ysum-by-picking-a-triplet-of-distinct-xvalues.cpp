class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++){
           mp[x[i]] = max(mp[x[i]], y[i]);
        }

        if(mp.size() < 3){
            return -1;
        }
        
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto [key, val]: mp){
            pq.push(val);
            if(pq.size() > 3){ 
                pq.pop();
            }    
        }

        int ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};