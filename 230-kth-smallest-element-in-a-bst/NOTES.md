class Solution {
void inorder(TreeNode* root, int k, priority_queue<int>& pq){
if(root == NULL){
return;
}
if(pq.size() < k){
pq.push(root->val);
}else{
if(pq.top() > root->val){
pq.pop();
pq.push(root->val);
}
}
inorder(root->left,k,pq);
inorder(root->right,k,pq);
}
public:
int kthSmallest(TreeNode* root, int k) {
//min heap priority of size k
priority_queue <int> pq;
//recurse inorder
inorder(root,k,pq);
//return the top
return pq.top();
}
};
​