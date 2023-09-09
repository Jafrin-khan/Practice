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
     ListNode* reverse(ListNode* head){
        
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
    
    int len(ListNode* head){
        int l = 0;
        while(head != NULL){
            l++;
            head = head->next;
        }
        return l;
    }
    
    ListNode* f(ListNode* head , int k){
        
        if(head == NULL || head->next == NULL || len(head) < k) return head;
        
        int kk = k-1;
        ListNode* t = head;
        
        while(kk--){
            t = t->next;
        }
        
        ListNode* nextList = t->next;
        nextList = f(nextList , k);
        t->next = NULL;
        
        ListNode* newHead = reverse(head);
        head->next = nextList;
        
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return f(head , k);
    }
};