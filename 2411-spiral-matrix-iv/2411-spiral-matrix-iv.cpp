/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int left = 0, right = n-1;
        int top = 0, bottom = m-1;

        ListNode* cur = head;

        while(left <= right && top <= bottom && cur != nullptr){
            for(int i=left; i<=right && cur != nullptr; i++){
                matrix[top][i] = cur->val;
                cur = cur->next;
            }
            top++;

            for(int i=top; i<=bottom && cur != nullptr; i++){
                matrix[i][right] = cur->val;
                cur = cur->next;
            }
            right--;

            if(left <= right){
                for(int i=right; i>=left && cur != nullptr; i--){
                    matrix[bottom][i] = cur->val;
                    cur = cur->next;
                }
                bottom--;
            }

            if(top <= bottom){
                for(int i=bottom; i>=top && cur != nullptr; i--){
                    matrix[i][left] = cur->val;
                    cur = cur->next;
                }
                left++;
            }
        }

        return matrix;
    }
};