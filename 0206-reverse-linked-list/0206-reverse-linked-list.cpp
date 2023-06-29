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
    
//     1 -> 2 -> 3 -> 4 -> 5
        
//     1 5->
        
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* nextList = head->next;
        head->next = NULL;
        
        nextList = reverseList(nextList);
        ListNode* tail = nextList;
        
        while(tail->next != NULL) tail = tail->next;
        
        tail->next = head;
        
        return nextList;
        
    }
};