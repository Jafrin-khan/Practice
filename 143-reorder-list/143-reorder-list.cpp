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
    
    
    ListNode* alternate(ListNode* h1 , ListNode* h2){
        
        if(h1 == NULL && h2 == NULL){
            return NULL;
        }
        
        if(h1 == NULL){
            return h2;
        }
        
        if(h2 == NULL){
            return h1;
        }
        
        ListNode* t1 = h1;
        ListNode* t2 = h2;
        
        ListNode* ans = new ListNode(0);
        ListNode* toReturn = ans;
        
        int flag = 1;
        while(h1 != NULL && h2 != NULL){
            
            if(flag){
                ans->next = h1;
                h1 = h1->next;
                flag = 0;
            }
            
            else{
                ans->next = h2;
                h2 = h2->next;
                flag = 1;
            }
            
            ans = ans->next;
            
        }
        
        if(h2){
            ans->next = h2;
            ans = ans->next;
        }
        
        return toReturn->next;
    }
    
    
    void reorderList(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp;
        
        while(fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        temp->next = NULL;
        slow = reverse(slow);
        
        ListNode* ans = alternate(head , slow);
        
        head = ans;
        
        
        
    }
};