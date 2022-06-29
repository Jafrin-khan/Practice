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
        
        if(head == NULL){
            return 0;
        }
        
        int l = 0;
        ListNode* temp = head;
        
        while(temp != NULL){
            l++;
            temp = temp->next;
        }
        
        return l;
    }
    int getDecimalValue(ListNode* head) {
        
        if(head == NULL){
            return 0;
        }
        
        ListNode* temp = head;
        int ans = 0;
        
        int len = getLen(head);
        int cnt = len - 1;
        
        while(temp != NULL){
            ans += pow(2,cnt--)*temp->val;
            temp = temp->next;
        }
        
        return ans;
        
    }
};