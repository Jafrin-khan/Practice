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
    
    /*
    TC = O(N) + O(M) + O(M+N)
    SC = O(1)
    */
    ListNode* reverse(ListNode* head){
        
        if(head == NULL){
            return head;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr != NULL){
            
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* h1 = reverse(l1);
        ListNode* h2 = reverse(l2);
        
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (h1 != NULL || h2 != NULL) || carry) {
            int sum = 0; 
            if(h1 != NULL) {
                sum += h1->val; 
                h1 = h1 -> next; 
            }
            
            if(h2 != NULL) {
                sum += h2 -> val; 
                h2 = h2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return reverse(dummy -> next); 
        
        
    }
};