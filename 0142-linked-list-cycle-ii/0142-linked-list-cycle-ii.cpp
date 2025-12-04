/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }

        ListNode *fast = head, *slow = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                break;
            }
        }

        if(fast == nullptr || fast->next == nullptr){
            return nullptr;
        }
        
        ListNode* temp = head;
        while(temp != slow){
            temp = temp->next;
            slow = slow->next;
        }

        return temp;
    }
};