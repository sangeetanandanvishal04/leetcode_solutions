class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mpp; //{char, idx}
        int n = order.size();

        for(int i=0; i<n; i++){
            mpp[order[i]] = i;
        }
        
        int N = words.size();
        for(int i=0; i<N-1; i++){
            int len = min(words[i].size(), words[i+1].size());
            int j = 0;
            while(j<len && words[i][j] == words[i+1][j]){
                j++;
            }  
            if(j < len && words[i][j] != words[i+1][j]){
                if(mpp[words[i][j]] > mpp[words[i+1][j]]){
                    return false;
                }
            }
            else if(words[i].size() > words[i+1].size()){
                return false;
            }
        }

        return true;
    }
};