class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0;
        priority_queue<double> pq;

        for(int num: nums){
            pq.push(num);
            sum += num;
        }

        int cnt = 0;
        double curSum = sum;
        while(!pq.empty()){
            double num = pq.top();
            pq.pop();

            if(curSum <= (sum / 2)){
                return cnt;
            }

            cnt++;
            curSum -= (num/2.0);
            pq.push(num/2.0);
        }

        return nums.size();
    }
};