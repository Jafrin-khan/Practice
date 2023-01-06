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
    
      ListNode* reverse(ListNode* head){
        
          if(head == NULL || head->next == NULL){
            return head;
        }
          
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
        
        int l = 0;
        while(head != NULL){
            head = head->next;
            l++;
        }
        return l;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL || getLen(head) < k){
            return head;
        }
        
         if(getLen(head) == k){
            return reverse(head);
        }
        
        ListNode* h = head;
        ListNode* t = h;
       
        
        int cnt = k-1;
        while(t != NULL && cnt--){
            t = t->next;
        }
        
        ListNode* nextNode = NULL;
        if(t){
        nextNode = t->next;
        t->next = NULL;
        }
        ListNode* newHead = reverse(head);
        head->next = reverseKGroup(nextNode, k);
        
        return newHead;
        
    }
};