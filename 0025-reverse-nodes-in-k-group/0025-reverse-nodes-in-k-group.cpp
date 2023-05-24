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
    //faltu code h kaam chalau dont refer it...jaise taise debug kara
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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int len = 0;
        ListNode* temp = head;
        
        while(len < k-1){
            if(temp == NULL) return head;
            len++;
            temp = temp->next;
        }
        
        if(temp == NULL) {
            if(len > k-1){ return reverseList(head);}
            else {return head; }  
        }
        
        ListNode* restList = temp->next;
        temp->next = NULL;
        
        ListNode* newHead = reverseList(head);
        
        ListNode* traverse = newHead;
        while(traverse->next != NULL) traverse = traverse->next;
        
        restList = reverseKGroup(restList, k);
        traverse->next = restList;
        
        return newHead;
           
    }
};