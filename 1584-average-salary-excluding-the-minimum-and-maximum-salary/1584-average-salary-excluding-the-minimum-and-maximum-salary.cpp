class Solution {
public:
    double average(vector<int>& salary) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int sum = 0;
        
        for(int num: salary){
            maxi = max(maxi, num);
            mini = min(mini, num);
            sum += num;
        }
        
        return (double)(sum - maxi - mini) / (salary.size()-2);
    }
};