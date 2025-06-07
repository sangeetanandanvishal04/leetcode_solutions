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
   bool Solve(TreeNode* root, long long max_val, long long min_val){
        if(root == nullptr){
            return true;
        }

        if(root->val < max_val && root->val > min_val){
            return Solve(root->right, max_val, root->val) && 
                                Solve(root->left, root->val, min_val);
        }

        return false;
   }    
public:
    bool isValidBST(TreeNode* root) {
        return Solve(root, LONG_MAX, LONG_MIN);
    }
};