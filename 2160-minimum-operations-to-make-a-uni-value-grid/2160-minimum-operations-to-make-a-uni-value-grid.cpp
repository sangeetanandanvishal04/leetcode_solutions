class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;
        for(auto row: grid){
            for(int val: row){
                values.push_back(val);
            }
        }

        sort(values.begin(), values.end());

        int median = values[values.size() / 2];
        int ops = 0;

        for(int val: values){
            if(abs(val - values[0]) % x != 0){
                return -1;
            }
            
            ops += abs(val - median) / x;
        }

        return ops;
    }
};