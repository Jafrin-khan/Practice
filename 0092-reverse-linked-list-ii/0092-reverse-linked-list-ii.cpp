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
    Time Complexity: O(N), Here N is the number of nodes in the linked list. In the worst case we need to traverse the list twice.
Auxiliary Space: O(1), As constant extra space is used.
    */
    
    ListNode* reverse(ListNode* head , ListNode* last){
        
          if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* prev = last;
        ListNode* curr = head;
        
        while(curr != last){
            
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        int l = left;
        
        ListNode* temp = head;
        ListNode* connect;
        left--;
        
        while(left-- && right--){
            connect = temp;
            temp = temp->next;
        }
        
        ListNode* nH = temp;
        
        while(temp != NULL && right--){
            temp = temp->next;
        }
        
        ListNode* nT = temp;
        
        //remember this step (line 63 to 70)
        if(l == 1){
            return reverse(nH , nT);
        }
        
        else{
            connect->next = reverse(nH , nT);
        }
        return head;
        
    }
};