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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head == NULL){
            return NULL;
        }
        
       
        while(head != NULL && head->val == val){
            head = head->next;
        }
        
         ListNode* temp = head;
       
        while(temp != NULL && temp->next != NULL){
            
            if(temp->next->val == val){
                ListNode* dup = temp->next;
                
                while(dup != NULL && dup->val == val){
                    dup = dup->next;
                }
                
                temp->next = dup;
            }
            
            temp = temp->next;
        }
        
        return head;
        
    }
};