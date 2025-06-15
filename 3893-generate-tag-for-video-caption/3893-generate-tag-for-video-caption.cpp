class Solution {
public:
    string generateTag(string caption) {
        string tag = "#";
        bool isFirst = true;

        int n = caption.length();
        
        for(int i=0; i<n; i++){
            while(i < n && caption[i] == ' '){
                i++;
            }    
            if(i >= n){ 
                break;
            }
            string word = "";
            while(i < n && caption[i] != ' '){
                char c = caption[i++];
                
                if(isalpha(c)){
                    word.push_back(tolower(c));
                }    
            }

            if(word.empty()){
                continue;
            }    

            if(!isFirst){
                word[0] = toupper(word[0]);
            }

            for(char c: word){
                if(tag.size() == 100){
                    break;
                }
                
                tag.push_back(c);
            }
            
            isFirst = false;
        }
        
        return tag;
    }
};