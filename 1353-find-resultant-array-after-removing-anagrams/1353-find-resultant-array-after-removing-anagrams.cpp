class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<unordered_map<char, int>> freq(n);
        
        for(int i=0; i<n; i++){
            for(char ch: words[i]){
                freq[i][ch]++;
            }
        }

        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1; i<n; i++){
            if(freq[i] != freq[i-1]){
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};