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
    Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times.

Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.
    */
  
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL){
            return l2;
        }
        
        if(l2 == NULL){
            return l1;
        }
        
        int carry = 0;
        ListNode* nH = new ListNode(0);
        ListNode* nT = nH;
        
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            
            nT->next = new ListNode(sum);
            nT = nT->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL){
            int sum = l1->val + carry;
            carry = sum/10;
            sum = sum%10;
            
            nT->next = new ListNode(sum);
            nT = nT->next;
            
            l1 = l1->next;
        }
        
         while(l2 != NULL){
            int sum =  l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            
            nT->next = new ListNode(sum);
            nT = nT->next;
            
            l2 = l2->next;
        }
        
        if(carry){
            nT->next = new ListNode(carry);
            nT = nT->next;
        }
        
        return nH->next;
        
        /*ye short code bhi dekho accha hai...logic same h bs OR condition daalke better bna diya hai
        
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
        */
        
    }
};