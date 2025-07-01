class Solution {
public:
    vector<string> findWords(vector<string>& words) {   
        int alpha[26]={0};
        vector<string> ans; 

        string key_rows[3]= {"qwertyuiop" , "asdfghjkl" , "zxcvbnm"};

        for(int i=0; i<3; i++){
            for(char ch: key_rows[i]){
                alpha[ch-'a'] = i+1;
            }
        }

        int i = 0; 
        for(string s:words){
            i = 0;
            int n = s.size();

            while((i<n) && 
                 ((alpha[tolower(s[i])-'a']) == alpha[tolower(s[0])- 'a'])){
                i++;
            }
            
            if(i == n){
                ans.push_back(s);
            }    
        }
        
        return ans;
    }
};