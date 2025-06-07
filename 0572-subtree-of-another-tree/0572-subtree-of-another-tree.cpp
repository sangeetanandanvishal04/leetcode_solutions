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
   bool isSame(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr){
            return true;
        }

        if(p == nullptr || q == nullptr){
            return false;
        }

        if(p->val == q->val){
            return isSame(p->left, q->left) && isSame(p->right, q->right);
        }
        else{
            return false;
        }
    }

   bool solve(TreeNode* root, TreeNode* subRoot){
        if(subRoot == nullptr){
            return true;
        }

        if(root == nullptr){
            return false;
        }

        if((root->val == subRoot->val) && isSame(root, subRoot)){
            return true;
        }
        return solve(root->left, subRoot) || solve(root->right, subRoot);
   }    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root, subRoot);
    }
};