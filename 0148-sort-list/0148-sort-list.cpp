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
    
    /*Explanation - optimised
    
    *****Merge Function****
    4->2->1->3
    
    4->2    1->3
    4 2     1 3
    
    2->4    1->3
    1->2->3->4
    
    *****find middle using hare and tortoise algo*****
    
    4->2->1->3
    f
    s
    
    working
    4->2->1->3
               f
          s
    
    
    /*
    TC = O(nlogn)
    SC = O(logn)..stack space
    */
    ListNode* merge(ListNode* l1 , ListNode* l2){
        if(l1 == NULL){
            return l2;
        }
        
        if(l2 == NULL){
            return l1;
        }
        
        ListNode* ans = new ListNode(0);
        ListNode* tail = ans;
        
        while(l1 && l2){
            if(l1->val <= l2->val){
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
                tail = tail->next;
            }
        }
        
        while(l1){
             tail->next = l1;
             l1 = l1->next;
             tail = tail->next;
        }
        
        while(l2){
             tail->next = l2;
             l2 = l2->next;
             tail = tail->next;
        }
        return ans->next;
    
    }
    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        ListNode* h1 = mergeSort(head);
        ListNode* h2 = mergeSort(slow);
        
        return merge(h1,h2);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};