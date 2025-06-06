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
    int countPathsFromNode(TreeNode* node, long long targetSum) {
        if(node == nullptr){
            return 0;
        }
        
        int count = 0;
        if(node->val == targetSum){
            count = 1;
        }
        
        count += countPathsFromNode(node->left, targetSum - node->val);
        count += countPathsFromNode(node->right, targetSum - node->val);
        
        return count;
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return 0;
        }
        
        int pathsFromRoot = countPathsFromNode(root, targetSum);
        
        int pathsFromLeft = pathSum(root->left, targetSum);
        int pathsFromRight = pathSum(root->right, targetSum);
        
        return pathsFromRoot + pathsFromLeft + pathsFromRight;
    }
};