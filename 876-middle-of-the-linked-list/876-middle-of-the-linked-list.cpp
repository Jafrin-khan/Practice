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
    
    int len(ListNode* head){
        
        int l = 0;
        while(head!=NULL){
            head = head->next;
            l++;
        }
        
        return l;
    }
    
    ListNode* middleNode(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        if(head == NULL){
            return NULL;
        }
        
        int l = len(head);
     
        l = (l/2) -1;
        
        
        while(l--){
            head = head->next;
        }
        
        return head->next;
        
        
    }
};