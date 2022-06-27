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
    
      ListNode* getReverse(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* prevPtr = NULL;
        ListNode* currPtr = head;
        
        while(currPtr!=NULL){
            ListNode* nextPtr = currPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = nextPtr;
        }
        
        return prevPtr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* temp = head;
        int l = k-1;
        
        while(l--){
            temp = temp->next;
            if(temp == NULL){
                return head;
            }
        }
        
        ListNode* n = temp->next;
        temp->next = NULL;
        
        ListNode* tail = head;
        ListNode* newHead = getReverse(head);
        
        ListNode* node = reverseKGroup(n,  k);
        tail->next = node;
        
        return newHead;
    }
};