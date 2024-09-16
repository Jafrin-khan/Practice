/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *hA, ListNode *hB) {
        
        ListNode* d1 = hA;
        ListNode* d2 = hB;

        while(d1 != d2){
            d1 = d1 == NULL? hB : d1->next;
            d2 = d2 == NULL? hA : d2->next;
        }

        return d1;
        
    }
};