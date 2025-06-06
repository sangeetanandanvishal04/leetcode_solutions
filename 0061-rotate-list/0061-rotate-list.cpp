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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }

        ListNode* cur = head;
        int cnt = 0;
        while(cur != nullptr){
            cnt++;
            cur = cur->next;
        }

        k = k%cnt;
        if(k == 0){
            return head;
        }

        ListNode* revHead = reverseList(head);
        ListNode* temp = revHead;
        for(int i=0; i<k-1; i++){
            temp = temp->next;
        }
        ListNode* second = temp->next;
        temp->next = nullptr;

        ListNode* first = reverseList(revHead);
        second = reverseList(second);

        temp = first;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = second;

        return first;
    }
};