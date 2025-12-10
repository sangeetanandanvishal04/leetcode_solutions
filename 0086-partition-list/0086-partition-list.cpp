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

void print(ListNode * head){
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(-1);
        ListNode* beforeHead = before;
        ListNode* after = new ListNode(0);
        ListNode* afterHead = after;
        
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

        before->next = afterHead->next;
        after->next = nullptr;
        
        return beforeHead->next;
    }
};