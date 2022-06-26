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
    ListNode* removeNthFromEnd(ListNode* h, int n) {
        
        if(h == NULL){
            return h;
        }
        
        if(h->next == NULL && n==1){
            return NULL;
        }
        
        
        
        ListNode* t = h;
        
        int len = 0;
        while(t != NULL){
            t = t->next;
            len++;
        }
        
        int ind = len-n;
        
       
        int cnt = 1;
        
        t = h;
        
         if(ind == 0){
             
             return h->next;
//              if(t->next->next == NULL){
//                  t->next == NULL;
//              }
//             while(t->next->next != NULL){
//                 t = t->next;
//             }
             
//              t->next = NULL;
        }
        
        while(t != NULL && cnt != ind){
            t = t->next;
            cnt++;
            
        }
        
        
        
        t->next = t->next->next;
        return h;
    }
};