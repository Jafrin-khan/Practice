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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* temp = head;
        while(temp != NULL){
            
            ListNode* dup = temp;
            while(dup != NULL && temp->val == dup->val){
                dup = dup->next;
            }
            
            temp->next = dup;
            temp = temp->next;
        }
        
        return head;
        
    }
};