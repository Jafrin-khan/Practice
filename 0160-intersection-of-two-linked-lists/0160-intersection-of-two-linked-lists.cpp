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
    
    int len(ListNode* head){
        int l = 0;
        while(head != NULL){
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        
        int l1 = len(h1);
        int l2 = len(h2);
        
        int d = max(l1,l2) - min(l1,l2);
        
        if(l1 >= l2){
            while(d--) {h1 = h1->next;}
        }
        
        else{
            while(d--) h2 = h2->next;
        }
        
        while(h1 != h2){
            h1 = h1->next;
            h2 = h2->next;
        }
        
        return h1;
    }
};