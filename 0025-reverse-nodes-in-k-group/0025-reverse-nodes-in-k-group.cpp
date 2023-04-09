
class Solution {
public:
    
     ListNode* reverse(ListNode* head){
        
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;  
    }
    
    int getLen(ListNode* head){
        
        if(head == NULL) return 0;
        int l = 0;
        while(head != NULL){
            head = head->next;
            l++;
        }
        return l;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
      
       int len = getLen(head);
       if(head == NULL || len < k) return head;
       
       ListNode* temp = head;
       int cnt = k-1;
        
       while(temp != NULL && cnt--) temp = temp->next;
        
        ListNode* nextNode = NULL;
        if(temp != NULL) nextNode = temp->next;
        
        if(!nextNode) return reverse(head);
        
        temp->next = NULL;
        ListNode* nT = head;
        ListNode* nH = reverse(head);
       
        nT->next = reverseKGroup(nextNode, k);
        
        return nH;
    }
};