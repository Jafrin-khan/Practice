TreeNode* f(int& ind ,vector<int>& preorder , int bound){
if(ind >= preorder.size() || preorder[ind] >= bound){
return NULL;
}
TreeNode* node = new TreeNode(preorder[ind++]);
node->left = f(ind , preorder , node->val);
node->right = f(ind , preorder , bound);
return node;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
int ind = 0;
return f(ind , preorder , INT_MAX);
}