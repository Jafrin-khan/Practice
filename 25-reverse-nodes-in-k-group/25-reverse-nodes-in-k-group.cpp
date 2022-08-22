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
        
        if(head == NULL){
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
        
        int n = k-1;
        
        ListNode* temp = head;
        
        while(n--){
            temp = temp->next;
        }
        
        ListNode* nextNode = temp->next;
        temp->next = NULL;
        
        ListNode* tail = head;
        ListNode* newHead = reverse(head);
        ListNode* restList = reverseKGroup(nextNode, k);
        
        tail->next = restList;
        
        return newHead;
        
    }
};