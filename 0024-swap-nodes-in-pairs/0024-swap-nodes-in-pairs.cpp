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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* newHead = head->next;
        ListNode *prev = head, *cur = head->next, *nextNode = nullptr;
        ListNode* lastSwappedTail = nullptr;

        while(prev != nullptr && cur != nullptr){
            nextNode = cur->next;

            cur->next = prev;
            prev->next = nextNode;

            if(lastSwappedTail != nullptr){
                lastSwappedTail->next = cur;
            }

            lastSwappedTail = prev;

            prev = nextNode;
            if(prev != nullptr){
                cur = prev->next;
            }
            else{
                cur = nullptr;
            }
        }

        return newHead;
    }
};