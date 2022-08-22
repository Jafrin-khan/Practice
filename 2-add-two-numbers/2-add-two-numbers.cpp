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
        
        ListNode* newHead = new ListNode(0);
        ListNode* newTail = newHead;
        int c = 0;
        int sum;
        while(l1 != NULL || l2 != NULL){
             sum = 0;
        
            if(l1){
                sum += l1->val;
                
                l1 = l1->next;
            }
            
            if(l2){
                sum += l2->val;
               
                l2 = l2->next;
            }
             
             sum += c;
             c = sum/10;
             sum = sum%10;
                
            
            ListNode* tail = new ListNode(sum);
            newTail->next = tail;
            newTail = newTail->next;
            
        }
        
        if(c){
            ListNode* tail = new ListNode(c);
            newTail->next = tail;
            newTail = newTail->next;
        }
        
        return newHead->next;
        
    }
};