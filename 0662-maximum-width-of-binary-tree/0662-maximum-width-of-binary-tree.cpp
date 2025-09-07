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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0}); //{node, idx}

        long long maxWidth = 1;
        while(!q.empty()){
            long long levelSize = q.size();
            long long levelStart = q.front().second;
            
            long long first, last;
            for(int i=0; i<levelSize; i++){
                TreeNode* node = q.front().first;
                long long cur_id = q.front().second - levelStart;
                q.pop();

                if(i == 0){
                    first = cur_id;
                }
                if(i == levelSize -1){
                    last = cur_id;
                }

                if(node->left != nullptr){
                    q.push({node->left, 2*cur_id+1});
                }
                if(node->right != nullptr){
                    q.push({node->right, 2*cur_id+2});
                }
            }

            maxWidth = max(maxWidth, last-first+1);
        }

        return (int)maxWidth;
    }
};