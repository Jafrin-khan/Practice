bool isEnd(){
return flag;
}
};
​
​
class Trie {
private:
Node* root;
public:
Trie() {
root = new Node();
}
void insert(string word) {
Node* node = root;
for(int i = 0 ; i < word.size() ; i++){
if(!node->containKey(word[i])){
node->put(word[i],new Node());
}
node = node->get(word[i]);
}
node->setEnd();
}
bool search(string word) {
Node* node = root;
for(int i = 0 ; i < word.size() ; i++){
if(!node->containKey(word[i])){
return false;
}
node = node->get(word[i]);
}
return node->isEnd();
}
bool startsWith(string prefix) {
Node* node = root;