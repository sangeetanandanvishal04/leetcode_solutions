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
public:
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr){
            return -1;
        }

        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN;
        int maxLevel = 0;
        int currentLevel = 0;

        while(!q.empty()){
            int size = q.size();
            int levelSum = 0;
            currentLevel++;

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;

                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }

            if(levelSum > maxSum){
                maxSum = levelSum;
                maxLevel = currentLevel;
            }
        }
        
        return maxLevel;
    }
};