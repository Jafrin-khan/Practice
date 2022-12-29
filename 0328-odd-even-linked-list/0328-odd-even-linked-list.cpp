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
    SC = O(1)...check space complexity i think it should be O(2)~O(1)
    */
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL){
            return head;
        }
        
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* trackEven = even;
        ListNode* trackOdd = odd;
        
        int flag = 1;
        
        while(head != NULL){
            
            if(flag){
                odd->next = head;
                odd = odd->next;
                flag = 0;
            }
            
            else{
                even->next = head;
                even = even->next;
                flag = 1;
            }
            
            head = head->next;
            
        }
        
        odd->next = trackEven->next;
        even->next = NULL;
        return trackOdd->next;
        
    }
};