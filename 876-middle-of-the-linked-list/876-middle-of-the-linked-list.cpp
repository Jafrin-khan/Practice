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
    
    int getLen(ListNode* head){
        
        int l = 0;
        while(head != NULL){
            head = head->next;
            l++;
        }
        
        return l;
    }
    ListNode* middleNode(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        int len = getLen(head);
        ListNode* temp = head;
        
        int mid = len/2;
        mid-=1;
        
        while(mid--){
            temp = temp->next;
        }
        
        return temp->next;
        
    }
};