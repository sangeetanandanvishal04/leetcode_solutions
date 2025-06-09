struct Node {
    Node* links[26] = {nullptr};
    bool flag = false;
    string word;

    bool containsKey(char ch){
        return links[ch-'a'] != nullptr;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(string w){
        flag = true;
        word = w;
    }

    bool isEnd(){
        return flag;
    }

    string getWord(){
        return word;
    }
};


class Solution {
private:
    Node* root = new Node();

    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, -1, 0, 1};

    void addWords(string word){
        Node* node = root;

        for(char ch: word){
            if(node->containsKey(ch) == false){
                node->put(ch, new Node());
            }

            node = node->get(ch);
        }

        node->setEnd(word);
    }

    void SearchWord(int row, int col, vector<vector<char>>& board, Node* node, vector<string>& result, int m, int n){
        char ch = board[row][col];
        if(ch == '#' || node->containsKey(ch) == false){
            return;
        }

        node = node->get(ch);
        if(node->isEnd() == true){
            result.push_back(node->getWord());
            node->flag = false;
        }

        board[row][col] = '#';

        for(int k=0; k<4; k++){
            int nrow = row + drow[k];
            int ncol = col + dcol[k];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                SearchWord(nrow, ncol, board, node, result, m, n);
            }
        }

        board[row][col] = ch;
    } 

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string word: words){
            addWords(word);
        }

        int m = board.size();
        int n = board[0].size();

        vector<string> result;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                SearchWord(i, j, board, root, result, m, n);
            }
        }

        return result;
    }
};