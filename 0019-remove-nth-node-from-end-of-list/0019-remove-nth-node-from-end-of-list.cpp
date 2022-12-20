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
    TC = O(N)
    SC = O(1)
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* t = head;
        
        int len = 0;
        
        while(t){
            t = t->next;
            len++;
        }
        
        if(n == len){
            return head->next;
        }
        
        int k = len - n - 1;
        
        while(k--){
            temp = temp->next;
        }
        
        if(n == 1){
            temp->next = NULL;
            return head;
        }
        
        ListNode* nextNode;
        nextNode = temp->next;
        temp->next = nextNode->next;
        
        return head;
        
    }
};