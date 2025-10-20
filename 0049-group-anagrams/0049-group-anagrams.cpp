class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for(string str: strs){
            vector<int> freq(26, 0);
            for(char ch: str){
                freq[ch - 'a']++;
            }

            string key;
            for(int num: freq){
                key += to_string(num) + "#";
            }
            mpp[key].push_back(str);
        }

        vector<vector<string>> result;
        for(auto it: mpp){
            result.push_back(it.second);
        }

        return result;
    }
};