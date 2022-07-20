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
        
          
        if(head==NULL){
            return head;
        }
        
        
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        
        while(head != NULL){
          
            if(head->next != NULL && head->next->val == head->val){
                
                ListNode* node = head;
                
                while(node != NULL && head->val == node->val){
                    node = node->next;
                }
                
                head = node;
            }
            
            else{
                
                temp->next = head;
                temp = temp->next;
                head = head->next;
                
            }
                
        }
        temp->next = NULL;
        return dummy->next;
        
    }
};