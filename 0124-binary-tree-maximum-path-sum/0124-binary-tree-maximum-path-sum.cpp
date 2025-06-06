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
    int Solve(TreeNode* root, int& maxi){
        if(root == nullptr){
            return 0;
        }

        int left = max(0, Solve(root->left, maxi));
        int right = max(0, Solve(root->right, maxi));

        int val = left + right + root->val;
        maxi = max(maxi, val);

        return root->val + max(left, right);
    }    
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        Solve(root, maxi);
        return maxi;
    }
};