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
        
        ListNode* left = new ListNode(0);
        ListNode* lh = left;
        ListNode* right = new ListNode(0);
        ListNode* rh = right;
        
        ListNode* temp = head;
        
        while(temp != NULL){
            
            if(temp->val < x){
                left->next = temp;
                left = left->next;
            }
            
            else{
                right->next = temp;
                right = right->next;
            }
            
            temp = temp->next;
        }
        
        if(rh->next){
            right->next = NULL;
        }
        
        if(lh->next){
            if(rh->next){
                left->next = rh->next;
            }
            
            else{
                left->next = NULL;
            }
        }
        
        else{
            return rh->next;
        }
        
        return lh->next;
    }
};