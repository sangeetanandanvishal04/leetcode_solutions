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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }

        unordered_map<int, ListNode*> mpp;
        int i=0, cnt=0;
        ListNode *cur = head;

        while(cur != nullptr){
            mpp[i] = cur;
            cnt++;
            i++;
            cur = cur->next;
        }

        ListNode* dummy = new ListNode(-1);
        i=0;
        cnt--;
        while(2*i < cnt){
            dummy->next = mpp[i];
            dummy = dummy->next;
            dummy->next = mpp[cnt-i];
            dummy = dummy->next;
            i++;
        }

        if(i == cnt-i){
            dummy->next = mpp[i];
            dummy = dummy->next;
        }

        dummy->next = nullptr;
    }
};