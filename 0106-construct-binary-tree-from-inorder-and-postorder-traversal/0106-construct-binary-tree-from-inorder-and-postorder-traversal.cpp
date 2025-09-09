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
    TreeNode* Solve(int inStart, int inEnd, int postStart, int postEnd, vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& inorderMap){
        if(inStart > inEnd || postStart > postEnd){
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int inRoot = inorderMap[postorder[postEnd]];
        int numsLeft = inRoot - inStart;

        root->left = Solve(inStart, inRoot-1, postStart, postStart+numsLeft-1, inorder, postorder, inorderMap);
        root->right = Solve(inRoot+1, inEnd, postStart+numsLeft, postEnd-1, inorder, postorder, inorderMap);

        return root;
    }     
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        
        unordered_map<int, int> inorderMap;
        for(int i=0; i<n; i++){
            inorderMap[inorder[i]] = i;
        }

        return Solve(0, n-1, 0, n-1, inorder, postorder, inorderMap);
    }
};