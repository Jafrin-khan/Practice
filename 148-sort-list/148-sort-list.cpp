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
    
    void store(ListNode* head , vector<int> &v){
        
        if(head == NULL){
            return;
        }
        
        ListNode* temp = head;
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
    }
    ListNode* sortList(ListNode* head) {
        
        
        ListNode* temp = head;
        vector<int> v;
        
        store(head , v);
        sort(v.begin(),v.end());
        int i = 0;
        
        while(temp != NULL){
            temp->val = v[i++];
            temp = temp->next;
        }
        
        return head;
    }
};