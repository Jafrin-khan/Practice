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
    
    ListNode* rotateRight(ListNode* head, int k) {
   
        if(head == NULL || head->next == NULL){
            return head;
        }     
        
        int l = 1;
        ListNode* t = head;
        
        while(t->next != NULL){
            t = t->next;
            l++;
        }
        

        t->next = head;
        k=k%l;
        
        int n = l - k -1;
        t = head;
        
        while(n--){
            
            t = t->next;
            
        }
        
        head = t->next;
        t->next = NULL;
        
        return head;
        
    }
};