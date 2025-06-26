class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i=0; i<n; i++){
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());

        priority_queue<pair<long long, long long>, 
        vector<pair<long long, long long>>, 
        greater<pair<long long, long long>>> pq; //{Burst Time, idx}
        
        vector<int> ans;
        int i = 0;
        long long AT = 0;

        while(i < n || !pq.empty()){
            if(pq.empty()){
                AT = max(AT, (long long)tasks[i][0]);
            }

            while(i < n && tasks[i][0] <= AT){
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            long long bt = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            
            AT += bt;
            ans.push_back(idx);
        }    

        return ans;                     
    }
};