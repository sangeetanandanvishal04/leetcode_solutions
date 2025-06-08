struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class WordDictionary {
private:
    Node* root;  

    bool dfsSearch(string word, int idx, Node* node){
        if(node == nullptr){
            return false;
        }

        if(idx == word.length()){
            return node->isEnd();
        }

        char ch = word[idx];

        if(ch == '.'){
            for(char ch='a'; ch <='z'; ch++){
                if(node->containsKey(ch) == true &&
                   dfsSearch(word, idx+1, node->get(ch))){
                    return true;
                }
            }

            return false;
        }
        else{
            if(node->containsKey(ch) == false){
                return false;
            }
            return dfsSearch(word, idx+1, node->get(ch));
        }
    }  
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(char ch: word){
            if(node->containsKey(ch) == false){
                node->put(ch, new Node());
            }

            node = node->get(ch);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        return dfsSearch(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */