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
    
     ListNode* Reverse(ListNode* left , ListNode* right){
        
        ListNode* curr = left;
        ListNode* prev = right;
        
        while(curr != right){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            
        }
        
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* prev = head;
        ListNode* nxt = head->next;
        ListNode* lp = head;
    
        
        int l = left - 1;
        int r = right - 1;
        
        while(l--){
            prev = lp;
            lp = lp->next;
        }
        
        while(r--){
            nxt = nxt->next;
        }
        
        if(left == 1){
            return Reverse(lp , nxt);
        }
        
        else{
            ListNode* temp = Reverse(lp , nxt);
            prev->next = temp;
        }
     return head;   
    }
};