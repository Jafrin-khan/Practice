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
    
    int len(ListNode* h){
        
        int l = 0;
        while(h != NULL){
            h = h->next;
            l++;
        }
        return l;
        
    }
    ListNode* removeNthFromEnd(ListNode* h, int n) {
        
        if(h == NULL){
            return h;
        }
        
        int l = len(h);
        ListNode* t = h;
        
        if(n == 1){
            
            if(t->next == NULL){
                return NULL;
            }
            
            while(t->next && t->next->next != NULL){
                t = t->next;
            }
            
            t->next = NULL;
            return h;
        }
        
        
        if(n == l){
            return h->next;
        }
        
        int toTraverse = l - n - 1;
        t = h;
        
        while(toTraverse--){
            
            t = t->next;
        }
        
        t->next = t->next->next;
        
        return h;
        
        
    }
};