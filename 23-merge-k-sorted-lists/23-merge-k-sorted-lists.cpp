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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        
        
        priority_queue<int , vector<int> , greater<int>> pq;
        
        for(int i = 0 ; i < lists.size() ; i++){
            
            ListNode* temp = lists[i];
            while(temp != NULL){
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        
        ListNode* newHead = new ListNode(0);
        ListNode* tail = newHead;
        
        while(!pq.empty()){
            
            ListNode* node = new ListNode(pq.top());
            pq.pop();
            
            tail->next = node;
            tail = tail->next;
        }
        
        return newHead->next;
        
    }
};