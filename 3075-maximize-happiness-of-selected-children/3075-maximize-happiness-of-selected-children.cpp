class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        
        long long ans = 0;
        int idx = happiness.size()-1;
        int d = 0;

        for(int i=0; i<k; i++){
            ans += (happiness[idx] - d) >= 0 ? (happiness[idx] - d) : 0;
            idx--;
            d++;
        }

        return ans;
    }
};