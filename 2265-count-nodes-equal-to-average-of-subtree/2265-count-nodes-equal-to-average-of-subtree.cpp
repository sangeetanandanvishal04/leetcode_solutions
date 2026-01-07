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
int cnt = 0;    
private:
    pair<int, int> Solve(TreeNode* root){
        if(root == nullptr){
            return {0, 0}; //{sum, nodeCnt}
        }

        pair<int, int> left = Solve(root->left);
        pair<int, int> right = Solve(root->right);

        int sum = left.first + right.first + root->val;
        int nodeCnt = left.second + right.second + 1;
        int avg = sum / nodeCnt;

        if(avg == root->val){
            cnt++;
        }

        return {sum, nodeCnt};
    }    
public:
    int averageOfSubtree(TreeNode* root) {
        Solve(root);
        return cnt;
    }
};