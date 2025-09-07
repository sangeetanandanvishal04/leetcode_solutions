/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap){
        if(root == nullptr){
            return;
        }
        
        if(root->left != nullptr){
            parentMap[root->left] = root;
        }
        if(root->right != nullptr){
            parentMap[root->right] = root;
        }

        dfs(root->left, parentMap);
        dfs(root->right, parentMap);
    }    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        dfs(root, parentMap);

        queue<pair<TreeNode*, int>> q; //{node, level}
        q.push({target, 0});
        unordered_map<TreeNode*, bool> vis;
        vis[target] = 1;

        vector<int> ans;
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(level == k){
                ans.push_back(node->val);
                continue;
            }

            if(node->left != nullptr && !vis[node->left]){
                q.push({node->left, level+1});
                vis[node->left] = 1;
            }
            if(node->right != nullptr && !vis[node->right]){
                q.push({node->right, level+1});
                vis[node->right] = 1;
            }
            if(parentMap.find(node) != parentMap.end() && !vis[parentMap[node]]){
                q.push({parentMap[node], level+1});
                vis[parentMap[node]] = 1;
            }
        }

        return ans;
    }
};