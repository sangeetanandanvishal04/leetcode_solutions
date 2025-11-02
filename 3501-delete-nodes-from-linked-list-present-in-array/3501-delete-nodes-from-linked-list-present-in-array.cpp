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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode* current = head;
        ListNode* prev = nullptr;

        while(current != nullptr){
            if(s.find(current-> val) != s.end()){
                if(prev == nullptr){ 
                    head = current->next;
                } 
                else{
                    prev->next = current->next;
                }
            } 
            else{
                prev = current;
            }

            current = current->next;
        }

        return head;
    }
};