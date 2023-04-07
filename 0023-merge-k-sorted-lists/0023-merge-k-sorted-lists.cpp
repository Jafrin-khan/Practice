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
     ListNode* solve(ListNode* l1,ListNode* l2){
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        if(l1->val < l2->val){
            l1->next = solve(l1->next,l2);
            return l1;
        }else{
            l2->next = solve(l1,l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* node = new ListNode (INT_MIN);
        for(auto it: lists){
            node = solve(node,it);
        }
        return node->next;
    }
};