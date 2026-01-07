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
    long long findSum(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return root->val + findSum(root->left) + findSum(root->right);
    }

    long long findMaxProduct(TreeNode* root, long long& totalSum, long long& maxProduct){
        if(root == nullptr){
            return 0;
        }    
        long long leftSum = findMaxProduct(root->left, totalSum, maxProduct);
        long long rightSum = findMaxProduct(root->right, totalSum, maxProduct);
        long long subtreeSum = root->val + leftSum + rightSum;
        
        if(subtreeSum != totalSum){ 
            long long product = subtreeSum * (totalSum - subtreeSum);
            maxProduct = max(maxProduct, product);
        }
        
        return subtreeSum;
    }  
public:
    int maxProduct(TreeNode* root) {
        const int MOD = 1e9 + 7;
        long long totalSum = 0;
        long long maxProduct = 0;

        totalSum = findSum(root);
        findMaxProduct(root, totalSum, maxProduct);
        return maxProduct % MOD;
    }
};