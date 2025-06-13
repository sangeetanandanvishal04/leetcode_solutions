class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int total = 0;
        for(int num: nums){
            if(num > 0){
                total += num;
                pq.push(num);
            }
        }
        
        int cnt = 0;
        int prev = 0;
        while(total != 0 && !pq.empty()){
            cnt++;

            int x = pq.top();
            pq.pop();

            int size = pq.size();

            while(!pq.empty() && pq.top()-x == 0){
                pq.pop();
            }  

            x -= prev;
            total -= (x*(size+1));
            prev += x; 
        }

        return cnt;
    }
};