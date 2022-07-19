/*We know, prorder: Root->Left->Right & postorder: Left->Right->Root
Let us take the sample test case given,
pre = [1,2,3,4,5,6,7] & post = [4,5,2,6,7,3,1]
Let n be the size of vectors.
On observation we can notice two facts:

pre[0] will be the root of tree and pre[0] = post[n-1]
Second last element of post (post[n-2]) will be the root of right subtree.
Using these facts we can make recursive calls, and passing the split arrays.*/

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.size()<1)
            return nullptr;
        int n = pre.size();
        int val = pre[0];
        TreeNode* root = new TreeNode(val);
        if(n==1)
            return root;
        int x = post[n-2];
        int ind = 0;
        for(int i=0;i<n;i++){
            if(pre[i]==x){
                ind = i;
                break;
            }
        }
        vector<int> preL(pre.begin()+1, pre.begin()+ind);
        vector<int> preR(pre.begin()+ind, pre.end());
        
        vector<int> postL(post.begin(), post.begin()+ind-1);
        vector<int> postR(post.begin()+ind-1, post.end()-1);
        
        root->left = constructFromPrePost(preL, postL);
        root->right = constructFromPrePost(preR, postR);
        
        return root;
    }
};