/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void preOrderTraversal(TreeNode* node, vector<TreeNode*>& nodeList) {
        if(node == nullptr){
            return;
        }    

        nodeList.push_back(node);
        preOrderTraversal(node->left, nodeList);
        preOrderTraversal(node->right, nodeList);
    }
public:
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }  
        vector<TreeNode*> nodeList;
        preOrderTraversal(root, nodeList);
        
        int n = nodeList.size();
        for(int i=0; i<n-1; i++) {
            nodeList[i]->left = nullptr;
            nodeList[i]->right = nodeList[i+1];
        }

        if(!nodeList.empty()){
            nodeList.back()->left = nullptr;
            nodeList.back()->right = nullptr;
        }
    }
};