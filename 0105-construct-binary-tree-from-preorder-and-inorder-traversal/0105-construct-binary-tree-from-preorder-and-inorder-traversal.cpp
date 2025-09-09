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
    TreeNode* Solve(int inStart, int inEnd, int preStart, int preEnd, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inorderMap){
        if(inStart > inEnd || preStart > preEnd){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inRoot = inorderMap[preorder[preStart]];
        int numsLeft = inRoot - inStart;

        root->left = Solve(inStart, inRoot-1, preStart+1, preStart+numsLeft, preorder, inorder, inorderMap);
        root->right = Solve(inRoot+1, inEnd, preStart+numsLeft+1, preEnd, preorder, inorder, inorderMap);
        return root;
    }      
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        unordered_map<int, int> inorderMap;
        for(int i=0; i<n; i++){
            inorderMap[inorder[i]] = i;
        }

        return Solve(0, n-1, 0, n-1, preorder, inorder, inorderMap);
    }
};