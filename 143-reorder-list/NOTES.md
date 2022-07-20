while(temp){
length++;
temp = temp->next;
}
// finding middle
int mid = length / 2;
int i = 0;
temp = head;
while(i < mid-1){
temp = temp->next;
i++;
}
// Seperating 1st and 2nd half and reversing 2nd half
ListNode* secondHalf = reverse(temp->next);;
temp->next = NULL;
// Till now We have done two step and ready for main logic how to change list pointers :)
ListNode* firstHalf = head;
// Carrying a previous second
ListNode* pSecond = NULL;
while(firstHalf){
// To track the first pointer so that it will not lost
// for eg : 1->2->2...  Here firstHalf is Node 1 and temp is tracking node 2 so that we don't loose
// track of firstHalf next pointer
ListNode* temp1 = firstHalf->next;
// Conecting first and second half
firstHalf->next = secondHalf;
// Now connecting Seond half to firstHalf next pointer i.e, temp
// Befroe doing that we need to keep track of second half next pointer