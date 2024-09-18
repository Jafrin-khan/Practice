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
        
        if(head == NULL) return head;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    int len(ListNode* head){
        int l = 0;
        ListNode* temp = head;
        
        while(temp){
            temp = temp->next;
            l++;
        }
        
        return l;
    }
    
    ListNode* f(ListNode* head , int k){
        
        if(head == NULL || head->next == NULL || len(head) < k) return head;
        
        // int l = len(head);
        // k = k%l;
        int kk = k-1;
        ListNode* temp = head;
        
        while(kk-- && temp) temp = temp->next;
        ListNode* nextList = temp->next;
         nextList = f(nextList , k);
        temp->next = NULL;
        
       
        
        ListNode* reverseList = reverse(head);
        head->next = nextList;
        
        return reverseList;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        return f(head , k);
        
    }
};