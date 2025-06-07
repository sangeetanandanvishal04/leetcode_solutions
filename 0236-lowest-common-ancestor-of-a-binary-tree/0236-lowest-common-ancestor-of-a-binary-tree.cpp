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
    TreeNode* Solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr){
            return nullptr;
        }

        if(root->val == p->val || root->val == q->val){
            return root;
        }

        TreeNode* left = Solve(root->left, p, q);
        TreeNode* right = Solve(root->right, p, q);

        if(left != nullptr && right != nullptr){
            return root;
        }

        if(left != nullptr || right != nullptr){
            return left != nullptr? left: right;
        }

        return nullptr;
    }    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return Solve(root, p, q);
    }
};