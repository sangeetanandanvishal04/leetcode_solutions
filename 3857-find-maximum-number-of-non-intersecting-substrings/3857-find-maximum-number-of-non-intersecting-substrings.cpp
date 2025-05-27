class Solution {
public:
    int maxSubstrings(const string &word) {
        int n = word.size();
        vector<vector<int>> pos(26);
        
        for(int i=0; i<n; i++){
            pos[word[i] - 'a'].push_back(i);
        }
        
        vector<pair<int,int>> validIntervals;
        for(int c=0; c<26; c++){
            for(int start : pos[c]){
                auto it = lower_bound(pos[c].begin(), pos[c].end(), start + 3);
                if(it != pos[c].end()){
                    int end = *it;
                    validIntervals.emplace_back(start, end);
                }
            }
        }
        
        sort(validIntervals.begin(), validIntervals.end(),[](auto &a, auto &b){
             return a.second < b.second;
        });
        
        int count = 0, last_end = -1;
        for(auto [start, end] : validIntervals){
            if(start > last_end){
                count++;
                last_end = end;
            }
        }
        
        return count;
    }
};