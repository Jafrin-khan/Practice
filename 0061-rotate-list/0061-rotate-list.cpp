class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL) return head;
        
        int len = 1;
        ListNode* temp = head;
        
        while(temp->next != NULL){
            len++;
            temp = temp->next;
        }
        
        temp->next = head;
        k%=len;
        k = len-k-1;
        
        temp = head;
        
        while(k--){
            temp = temp->next;
        }
        
        ListNode* newHead = temp->next;
        temp->next = NULL;
        
        return newHead;
    }
};