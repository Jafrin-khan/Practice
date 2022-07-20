Node* flatten(Node* head) {
if(head == NULL){
return head;
}
Node* temp = head;
while(temp != NULL){
if(temp->child){
Node* laterList = temp->next;
Node* toFix = flatten(temp->child);
temp->next = toFix;
toFix->prev = temp;
Node* treverseToFix = toFix;
while(treverseToFix->next != NULL){
treverseToFix = treverseToFix->next;
}
if(laterList){
treverseToFix->next = laterList;
laterList->prev = treverseToFix;
}
else{
treverseToFix->next = NULL;
}
temp->child = NULL;
}
temp = temp->next;
}
return head;
}