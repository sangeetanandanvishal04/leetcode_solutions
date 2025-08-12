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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }

        // {vertical_line -> {level -> multiset of values}}
        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode*, pair<int, int>>> q; //{node, {vertical_line, level}}
        q.push({root, {0, 0}});

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int line = q.front().second.first;
            int level = q.front().second.second;
            q.pop();

            mpp[line][level].insert(node->val);

            if(node->left != nullptr){
                q.push({node->left, {line-1, level+1}});
            }
            if(node->right != nullptr){
                q.push({node->right, {line+1, level+1}});
            }
        }

        for(auto it: mpp){
            vector<int> col;
            for(auto [_, st]: it.second){
                for(int val: st){
                    col.push_back(val);
                }
            }

            ans.push_back(col);
        }

        return ans;
    }
};