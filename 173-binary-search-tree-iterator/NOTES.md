stack<TreeNode*> st;
BSTIterator(TreeNode* root) {
pushAllLeft(root);
}
int next() {
TreeNode* top = st.top();
st.pop();
pushAllLeft(top->right);
return top->val;
}
bool hasNext() {
return !st.empty();
}
void pushAllLeft(TreeNode* root){
while(root != NULL){
st.push(root);
root = root->left;
}
}