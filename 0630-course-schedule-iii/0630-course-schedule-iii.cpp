class Solution {
private:
    static bool comp(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }    
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        int day = 0;
        priority_queue<int> pq;
        
        for(auto vec: courses){
            int dur = vec[0];
            int lastDay = vec[1];

            day += dur;
            pq.push(dur);

            if(day > lastDay){
                day -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};