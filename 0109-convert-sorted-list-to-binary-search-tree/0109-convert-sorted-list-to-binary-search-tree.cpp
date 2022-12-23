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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
Time complexity: O(n log(n)).
There will be log(n) recursive levels because each time we split it to into half & in each level we loop through the whole list, divided into small parts.
Space complexity: O(log(n)).
We will have log(n) recursive calls on stack.
    */
    
    /*
    same as that of making BST from sorted array....prev accepted ans4
    
    TC = O(NlogN)
    SC = O(logN)
    */
   
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head == NULL){
            return NULL;
        }
        
        if(head->next == NULL)
            return new TreeNode(head->val);
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        ListNode* mid = slow;
        TreeNode* root = new TreeNode(mid->val);
        
        prev->next = NULL;
        ListNode* rightHalf = mid->next;
        
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(rightHalf);
        
        return root;
        
    }
};