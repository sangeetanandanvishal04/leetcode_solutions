class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord){
                return steps;
            }
            
            int n = word.length();
            for(int i=0; i<n; i++){
                string original = word;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({word, steps+1});
                        st.erase(word);
                    }
                }
                word = original;
            }
        }

        return 0;
    }
};