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
    
    ListNode* f(ListNode* head){
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* temp = head;
        ListNode* newHead = temp->next;
        ListNode* nextNode = newHead->next;
        
        newHead->next = temp;
        temp->next = swapPairs(nextNode);
        
        return newHead;
        
    }
    ListNode* swapPairs(ListNode* head) {
        
        return f(head);
        
    }
};