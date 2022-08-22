/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    int getLen(ListNode* head){
        int l = 0;
        
        while(head != NULL){
            head = head->next;
            l++;
        } 
        
        return l;
    }

    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2){
        
        int l1 = getLen(h1);
        int l2 = getLen(h2);
        
        int d = abs(l1 - l2);
        
        if(l2 > l1){
            
            while(d--){
                h2 = h2->next;
            }
            
        }
        
        else{
             while(d--){
                h1 = h1->next;
            }
        }
        
        while(h1 != h2){
            h1 = h1->next;
            h2 = h2->next;
        }
        
        return h1;
        
    }
};