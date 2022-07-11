ListNode* rotateRight(ListNode* head, int k) {
if(head == NULL || head->next == NULL || k==0){ // Base case
return head;
}
ListNode* curr=head;  // Dummy node
int c=1;
while(curr->next!=NULL)
{
c++;       // Counted the length of the linked list
curr=curr->next;
}
curr->next=head;    // Connected the last node to the head
k=k%c;
k=c-k;
while(k--)
{
curr=curr->next;
}
head=curr->next;
curr->next=NULL;
return head;
}