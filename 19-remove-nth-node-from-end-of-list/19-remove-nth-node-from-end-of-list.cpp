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
    
    int getLen(ListNode* head){
        
        int l = 0;
        while(head != NULL){
            head = head->next;
            l++;
        }
        
        return l;
    }
   
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == NULL){
            return head;
        }
        
        if(head->next == NULL && n == 1){
            return NULL;
        }
        
        int len = getLen(head);
        int point = len-n;
        
        if(point == 0){
            return head->next;
        }
        
        point-=1;
        
        ListNode* temp = head;
        
        while(point--){
            temp = temp->next;
        }
        
        if(temp->next->next != NULL){
            ListNode* newTemp = temp->next->next;
            temp->next = newTemp;
        }
        
        else{
        temp->next = temp->next->next;
        }
        return head;
    }
};