class Solution {  
private:
    static bool comp(pair<double, int>& a, pair<double, int>& b){
        return a.first < b.first;
    }    
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();

        vector<pair<double, int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({(double)wage[i] / quality[i], quality[i]});
        }

        sort(vec.begin(), vec.end(), comp);

        priority_queue<int> pq;
        long long sum = 0;
        double ans = 1e18;

        for(auto v: vec){
            double ratio = v.first;
            int q = v.second;
            sum += q;
            pq.push(q);

            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k){
                ans = min(ans, sum*ratio);
            }
        }

        return ans;
    }
};