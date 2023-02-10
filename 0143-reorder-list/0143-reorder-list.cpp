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
    /*
    TC = O(N/2) + O(N/2) + O(N) ~ O(N)
    SC = O(1)
    */
    
    ListNode* reverse(ListNode* head){
        
        if(head == NULL) return NULL;
        
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
        
        if(head == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
       return slow;
    }
    
    void reorderList(ListNode* head) {
        
        if(head == NULL) return;
        ListNode* mid =findMid(head);
        ListNode* t2 = mid->next;
        mid->next = NULL;
        
        ListNode* t1 = head;
        t2 = reverse(t2);
        
        ListNode* ans = new ListNode(0);
        ListNode* tail = ans;
        
        while(t1 || t2){
            if(t1){
            ans->next = t1;
            ans = ans->next;
            t1 = t1->next;
            }
            
            if(t2){
            ans->next = t2;
            ans = ans->next;
            t2 = t2->next;
            }
        }
        
        head =  ans->next;
    }
};