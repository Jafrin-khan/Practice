TreeNode* sortedListToBST(ListNode* head) {
if(head == NULL)
return NULL;
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
//break the two halves
prev->next = NULL;
//slow is pointing to the middle node.
TreeNode* newRoot = new TreeNode(slow->val);
newRoot->left = sortedListToBST(head);
newRoot->right = sortedListToBST(slow->next);
return newRoot;
}