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
   
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = new ListNode(0);
        ListNode* newHead = ans;
        int carry = 0;
        
        while(l1 || l2 || carry){
            int sum = 0;
            if(l1) {sum += l1->val;l1 = l1->next;}
            if(l2) {sum += l2->val; l2 = l2->next;}
            if(carry) sum += carry;
            
            carry = sum/10;
            sum%=10;
            
            ans->next = new ListNode(sum);
            ans = ans->next;
        
        }
        
        return newHead->next;
    }
};