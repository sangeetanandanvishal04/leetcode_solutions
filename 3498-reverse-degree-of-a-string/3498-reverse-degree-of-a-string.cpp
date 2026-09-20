class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int total_degree = 0;
        
        for(int i=0; i<n; i++){
            int idx_alphabet = 26 - (s[i] - 'a');
            total_degree += idx_alphabet*(i+1); 
        }

        return total_degree;
    }
};