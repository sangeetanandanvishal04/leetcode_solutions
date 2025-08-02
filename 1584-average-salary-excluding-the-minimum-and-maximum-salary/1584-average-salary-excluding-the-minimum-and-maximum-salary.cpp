class Solution {
public:
    double average(vector<int>& salary) {
        int maxi = *max_element(salary.begin(), salary.end());
        int mini = *min_element(salary.begin(), salary.end());
        
        int sum = accumulate(salary.begin(), salary.end(), 0);
        
        return (double)(sum - maxi - mini) / (salary.size()-2);
    }
};