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
    int leftDepth(TreeNode* node) {
        int depth = 0;
        while(node){
            node = node->left;
            depth++;
        }
        return depth;
    }

    int rightDepth(TreeNode* node) {
        int depth = 0;
        while(node){
            node = node->right;
            depth++;
        }
        return depth;
    }    
public:
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }

        int left_depth = leftDepth(root);
        int right_depth = rightDepth(root);

        if(left_depth == right_depth){
            return (1 << left_depth)-1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
};