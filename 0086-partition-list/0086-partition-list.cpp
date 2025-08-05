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
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeHead = new ListNode(0);
        ListNode* before = beforeHead;
        ListNode* afterHead = new ListNode(0);
        ListNode* after = afterHead;
        
        ListNode* temp = head;
        while(temp != nullptr){
            if(temp->val < x){
                before->next = temp;
                before = before->next;
            }
            else{
                after->next = temp;
                after = after->next;
            }
            temp = temp->next;
        }
        
        after->next = nullptr;
        before->next = afterHead->next;
        ListNode* result = beforeHead->next;
        
        delete beforeHead;
        delete afterHead;
        
        return result;
    }
};