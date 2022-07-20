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
    
    
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        temp->next = NULL;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        return merge(l1 , l2);
        
    }
    
    ListNode* merge(ListNode* h1 , ListNode* h2){
        
        ListNode* t1 = h1;
        ListNode* t2 = h2;
        
        ListNode* ans = new ListNode(0);
        ListNode* ansT = ans;
        
        while(t1 != NULL && t2 != NULL){
            
            if(t1->val <= t2->val){
                ansT->next = t1;
                t1 = t1->next;
            }
            
            else{
                ansT->next = t2;
                t2 = t2->next;
            }
            
            ansT = ansT->next;
        }
        
        
        while(t1 != NULL){
            ansT->next = t1;
            t1 = t1->next;
            ansT = ansT->next;
        }
        
         while(t2 != NULL){
            ansT->next = t2;
            t2 = t2->next;
            ansT = ansT->next;
        }
        
                
         return ans->next;
        
    }
    
    
};