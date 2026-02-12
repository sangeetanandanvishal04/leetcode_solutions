class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;

        for(int i=0; i<n; i++){
            vector<int> cnt(26, 0);
            int maxi = 0, unique_cnt = 0;
            for(int j=i; j<n; j++){
                int char_idx = s[j] - 'a';
                
                if(cnt[char_idx] == 0){
                    unique_cnt++;
                }

                cnt[char_idx]++;

                maxi = max(maxi, cnt[char_idx]);
                if(maxi*unique_cnt == j-i+1){
                    ans = max(ans, j-i+1);
                }
            }
        }

        return ans;
    }
};