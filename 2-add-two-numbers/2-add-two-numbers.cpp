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
        
        if(l1 == NULL){
            return l2;
        }
        
        if(l2 == NULL){
            return l1;
        }
        
        ListNode* newHead = new ListNode(0);
        ListNode* tail = newHead;
  
        int ans = 0;
        int c = 0;
        
        while(l1 != NULL || l2 != NULL){
            
            ans = 0;
            if(l1){
                ans += l1->val;
                l1 = l1->next;
            }
            
            if(l2){
                ans += l2->val;
                l2 = l2->next;
            }
            
            ans += c;
            c = ans/10;
            ans = ans%10;
            
            ListNode* node = new ListNode(ans);
            tail->next = node;
            tail = tail->next;
        }
        
        if(c){
            ListNode* node = new ListNode(c);
            tail->next = node;
            tail = tail->next;
            
        }
        
        return newHead->next;
        
    }
};