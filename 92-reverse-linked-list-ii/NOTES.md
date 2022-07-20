ListNode* lp = head;
ListNode* rp = head;
int l = left -1;
int r = right - 1;
while(l--){
prev = lp;
lp = lp->next;
}
while(r--){
rp = rp->next;
nxt = nxt->next;
}
if(left == 1){
return Reverse(lp,nxt);
}
else{
ListNode* temp = Reverse(lp,nxt);
prev->next = temp;
}
return head;
}