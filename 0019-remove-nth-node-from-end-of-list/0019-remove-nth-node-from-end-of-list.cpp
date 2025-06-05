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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr && n==1){
            return nullptr;
        }

        int cnt = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            cnt++;
            temp = temp->next;
        }

        int pos = cnt-n;
        if(pos < 0){
            return head;
        }

        if(pos == 0){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int i=0;
        temp = head;
        while(i < pos-1){
            temp = temp->next;
            i++;
        }

        ListNode* cur = temp->next;
        temp->next = cur->next;

        delete cur;
        return head;
    }
};