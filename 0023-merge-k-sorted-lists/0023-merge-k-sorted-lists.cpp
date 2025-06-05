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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0){
            return nullptr;
        }

        vector<ListNode*> ptrs = lists;
        ListNode* dummy = new ListNode(0);
        ListNode* lead = dummy;

        while(true){
            int min_idx = -1;
            int min_val = INT_MAX;

            for(int i=0; i<n; i++){
                if(ptrs[i] != nullptr && ptrs[i]->val < min_val){
                    min_val = ptrs[i]->val;
                    min_idx = i;
                }
            }

            if(min_idx == -1){
                break;
            }

            dummy->next = ptrs[min_idx];
            ptrs[min_idx] = ptrs[min_idx]->next;
            dummy = dummy->next;
        }

        return lead->next;
    }
};