/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "";
        }

        queue<TreeNode*> q;
        q.push(root);
        string result;

        while(!q.empty()){
            int levelSize = q.size();
            result.push_back('(');

            for(int i=0; i<levelSize; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node != nullptr){
                    result += to_string(node->val);
                    result.push_back(',');

                    q.push(node->left);
                    q.push(node->right);
                }
                else{
                    result += "null,";
                }
            }

            result.push_back(')');
        }

        return result;
    }

    TreeNode* deserialize(string data) {
        if(data.empty()){
            return nullptr;
        }

        vector<string> vals;
        string cur;
        for(char ch: data){
            if(ch == '(' || ch == ')'){
                continue;
            }
            else if(ch == ','){
                if(!cur.empty()){
                    vals.push_back(cur);
                    cur.clear();
                }
            }
            else{
                cur.push_back(ch);
            }
        }

        if(vals.empty() || vals[0] == "null"){
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i=1;
        int n = vals.size();
        while(!q.empty() && i<n){
            TreeNode* node = q.front();
            q.pop();

            if(i<n && vals[i] != "null"){
                node->left = new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }
            i++;

            if(i<n && vals[i] != "null"){
                node->right = new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));