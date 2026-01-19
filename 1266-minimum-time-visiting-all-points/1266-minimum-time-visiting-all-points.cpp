class Solution {
private:
    int maxNorm(vector<int>& P, vector<int>& Q){
        return max(abs(P[0]-Q[0]), abs(P[1]-Q[1]));
    }

public:    
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        vector<int> prev = points[0];

        for(auto point: points){
            ans += maxNorm(point, prev);
            prev = point;
        }

        return ans;
    }
};