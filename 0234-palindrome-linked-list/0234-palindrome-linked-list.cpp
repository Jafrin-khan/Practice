
class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL) return head;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
    
    ListNode* findMid(ListNode* head){
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* mid = findMid(head);
        ListNode* rightList = reverseList(mid->next);
        mid->next = NULL;
        
        ListNode* t1 = head;
        ListNode* t2 = rightList;
        
        while(t1 != NULL && t2 != NULL){
            if(t1->val != t2->val) return false;
            t1 = t1->next;
            t2 = t2->next;
        }
        
        return true;
          
    }
};