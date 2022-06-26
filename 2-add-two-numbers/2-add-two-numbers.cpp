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
    
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* prevPtr = NULL;
        ListNode* currPtr = head;
        
        while(currPtr!=NULL){
            ListNode* nextPtr = currPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = nextPtr;
        }
        
        return prevPtr;
    }
    ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
        
             if(h1 == NULL && h2 == NULL){
            return NULL;
        }
        
        if(h1 == NULL || h2 == NULL){
            return h1 == NULL ? h2 : h1;
        }
        
        // h1 = reverseList(h1);
        // h2 = reverseList(h2);
        
        ListNode* h = new ListNode(0);
        ListNode* t = h;
        
        int carry = 0;
        int ans = 0;
        
        while(h1 != NULL && h2 != NULL){
            
            ans = (h1->val + h2->val) + carry;
            carry = ans/10;
            ans = ans%10;
            
            ListNode* node = new ListNode(ans);
            t->next = node;
            t = t->next;
            
            h1 = h1->next;
            h2 = h2->next;
        }
        
        while(h1 != NULL){
            ans = h1->val + + carry;
            carry = ans/10;
            ans = ans%10;
            
            ListNode* node = new ListNode(ans);
            t->next = node;
            t = t->next;
            
            h1 = h1->next;
            
        }
        
        while(h2 != NULL){
            ans = h2->val + + carry;
            carry = ans/10;
            ans = ans%10;
            
            ListNode* node = new ListNode(ans);
            t->next = node;
            t = t->next;
            
            h2 = h2->next;
            
        }
        
        if(carry){
            ListNode* node = new ListNode(carry);
            t->next = node;
            t = t->next;
        }
        
        return h->next;;
        
    }
};