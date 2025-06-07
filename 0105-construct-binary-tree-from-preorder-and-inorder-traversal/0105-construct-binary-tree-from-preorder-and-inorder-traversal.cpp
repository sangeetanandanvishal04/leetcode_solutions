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
    TreeNode* Solve(vector<int>& preorder, vector<int>& inorder, int& idx){
        if(inorder.empty()){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[idx]);
        
        int n = inorder.size();
        vector<int> leftIn, rightIn;
        int i=0;
        while(i<n){
            if(inorder[i] == preorder[idx]){
                break;
            }
            leftIn.push_back(inorder[i]);
            i++;
        }
        i++;

        while(i<n){
            rightIn.push_back(inorder[i]);
            i++;
        }
        
        idx++;
        root->left = Solve(preorder, leftIn, idx);
        root->right = Solve(preorder, rightIn, idx);
        return root; 
    }    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return Solve(preorder, inorder, idx);
    }
};