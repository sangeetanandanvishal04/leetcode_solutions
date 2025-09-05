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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        
        vector<vector<int>> result;
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);

        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int> currentLevel;

            for(int i=0; i<size; i++){
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                currentLevel.push_back(node->val);

                if(node->left != nullptr){
                    nodesQueue.push(node->left);
                }
                if(node->right != nullptr){
                    nodesQueue.push(node->right);
                }    
            }

            result.push_back(currentLevel);
        }

        return result;
    }
};