class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> suffixYes(n+1, 0);
        
        for(int i=n-1; i>=0; i--){
            if(customers[i] == 'Y'){
                suffixYes[i] = suffixYes[i+1] + 1;
            }
            else{
                suffixYes[i] = suffixYes[i+1];
            }
        }
        
        int bestTime = 0;
        int min_penalty = INT_MAX;
        int curNo = 0;
        for(int i=0; i<=n; i++){
            int penalty = curNo + suffixYes[i];
            if(penalty < min_penalty){
                min_penalty = penalty;
                bestTime = i;
            }

            if(i < n && customers[i] == 'N'){
                curNo++;
            }
        }

        return bestTime;
    }
};