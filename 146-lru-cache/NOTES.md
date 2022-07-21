void addnode(node* newnode){
node* temp = head->next;
newnode->next = temp;
newnode->prev = head;
head->next = newnode;
temp->prev = newnode;
}
void deletenode(node* delnode){
node* delprev = delnode->prev;
node* delnext = delnode->next;
delprev->next = delnext;
delnext->prev = delprev;
}
int get(int key_) {
if(m.find(key_) != m.end()){
node* resnode = m[key_];
int res = resnode->val;
m.erase(key_);
deletenode(resnode);
addnode(resnode);
m[key_] = head->next;
return res;
}
return -1;
}
void put(int key_, int value) {
if(m.find(key_) != m.end()){
node* existingnode = m[key_];
m.erase(key_);
deletenode(existingnode);
}
if(m.size() == cap){
m.erase(tail->prev->key);
deletenode(tail->prev);
}
addnode(new node(key_,value));
m[key_] = head->next;
}