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
private:
    ListNode* findMid(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }

        ListNode *slow = head, *fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;
        return second;
    }   

    ListNode* reverseList(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode *prev = nullptr, *cur = head, *nextNode=head;
        while(cur != nullptr){
            nextNode = nextNode->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }

        return prev;
    }     
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return true;
        }

        ListNode* second = findMid(head);
        second = reverseList(second);
        ListNode* first = head;

        while(first != nullptr && second != nullptr){
            if(first->val != second->val){
                return false;
            }

            first  = first->next;
            second = second->next;
        }

        return true;
    }
};