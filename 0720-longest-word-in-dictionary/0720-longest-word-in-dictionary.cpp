class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        queue<vector<string>> q; //list of words
        for(string word: words){
            if(word.length() == 1){
                q.push({word});
            }
        }
        
        string maxi = "";
        while(!q.empty()){
            vector<string> temp = q.front();
            q.pop();
            
            string word = temp.back();
            if(word.length() > maxi.length()){
                maxi = word;
            }
            if(word.length() == maxi.length()){
                maxi = min(maxi, word);
            }
            
            for(char ch='a'; ch<='z'; ch++){
                word.push_back(ch);
                if(st.find(word) != st.end()){
                    temp.push_back(word);
                    q.push(temp);
                }
                word.pop_back();
            }
        } 
        
        return maxi;
    }
};