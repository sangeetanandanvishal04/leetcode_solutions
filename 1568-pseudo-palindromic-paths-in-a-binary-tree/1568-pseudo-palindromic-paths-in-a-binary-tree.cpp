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
    int Solve(TreeNode* root, unordered_map<int, int>& mpp){
        if(root == nullptr){
            return 0;
        }
        
        mpp[root->val]++;
        
        int res = 0;
        if(root->left == nullptr && root->right == nullptr){
            int cnt = 0;
            for(auto it: mpp){
                if(it.second % 2 != 0){
                    cnt++;
                    if(cnt > 1){
                        break;
                    }
                }
            }

            if(cnt <= 1){
                res += 1;
            }    
        }
        else{
            res += Solve(root->left, mpp);
            res += Solve(root->right, mpp);
        }

        mpp[root->val]--;
        if(mpp[root->val] == 0){
            mpp.erase(root->val);
        }

        return res;
    }    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int> mpp; //{nodeVal, cnt}
        return Solve(root, mpp);
    }
};