ListNode* dup = temp;
while(dup != NULL && temp->val == dup->val){
dup = dup->next;
}
temp->next = dup;
temp = temp->next;