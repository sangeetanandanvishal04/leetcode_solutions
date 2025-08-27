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
    pair<bool, int> Check(TreeNode* root){
        if(root == nullptr){
            return {true, 0}; //{balanced, height}
        }
        
        pair<bool, int> lt = Check(root->left);
        if(lt.first == false){
            return {lt.first, lt.second + 1};
        }
        
        pair<bool, int> rt = Check(root->right);
        if(rt.first == false){
            return {rt.first, rt.second + 1};
        }
        
        if(abs(lt.second - rt.second) > 1){
            return {false, max(lt.second, rt.second) + 1};
        }
        return {true, max(lt.second, rt.second) + 1};
    }   
public:
    bool isBalanced(TreeNode* root) {
        return Check(root).first;
    }
};