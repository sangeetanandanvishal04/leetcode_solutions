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
    int getDia(TreeNode* root, int& maxi){
        if(root == nullptr){
            return 0;
        }

        int left = getDia(root->left, maxi);
        int right = getDia(root->right, maxi);
        
        maxi = max(maxi, left+right);

        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        getDia(root, maxi);
        return maxi;
    }
};