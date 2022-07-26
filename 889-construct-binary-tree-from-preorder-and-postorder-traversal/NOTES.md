TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
if(pre.size() < 1){
return NULL;
}
int n = pre.size();
int val = pre[0];
TreeNode* root = new TreeNode(val);
if(n == 1){
return root;
}
int x = post[n-2];
int ind = 0;
for(int i = 0 ; i < n ; i++){
if(pre[i] == x){
ind = i;
break;
}
}
vector<int> preL(pre.begin() + 1 , pre.begin() + ind);
vector<int> preR(pre.begin() + ind , pre.end());
vector<int> postL(post.begin() , post.begin() + ind - 1);
vector<int> postR(post.begin() + ind - 1 , post.end() - 1);
root->left = constructFromPrePost(preL, postL);
root->right = constructFromPrePost(preR, postR);
return root;
}