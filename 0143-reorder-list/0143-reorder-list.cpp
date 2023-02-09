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
    TC = O(n/2) + O(n/2) + O(n/2)
    SC = O(1)
    */
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }
        return prev;
    }
    void reorderList(ListNode* head) {

          ListNode* m = middle(head);
          ListNode* t2 = m->next;
          m->next = NULL;

          ListNode* t1 = head;
          t2 = reverse(t2);

          ListNode* n1;
          ListNode* n2;

          while(t1 != NULL && t2 != NULL){

              n1 = t1->next;
              t1->next = t2;

              n2 = t2->next;
              t2->next = n1;

              t1 = n1;
              t2 = n2;

          }
        
    }
};