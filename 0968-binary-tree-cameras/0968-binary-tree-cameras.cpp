/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*THIS IS ANOTHER APPROACH WITHOUT USING SET
Upvote if found helpful :

Time Complexity : O(n), Space Complexity : O(h) [n = number of nodes, h = height of the tree]

In this approach we are using recursion in which we are transferring the root of the tree and initial number of cameras (n) i.e. 0 to the function status.

The number of cameras are transferred into the status function by reference so it gets updated automatically when a new camera is added to any node. As no node is traversed more than once so the end number of cameras is the answer. So we can use thereturn value of status function for checking the status of the node on which it was performed.

In status function the meaning of the return values and functions of steps inside it are mentioned in the code.

The status function gets automatically executed when we check status of the root in the minCameraCover function. So we can directly return n.

The code is as follows :

class Solution {
public:
    //Return value - Description
    //0 - node don't have camera(0) and is not being watched(0) total 0.
    //1 - node don't have camera(0) and is being watched(1) total 1.
    //2 - node has camera(1) and is being watched(1) total 2.
    int status(TreeNode* root,int &n){
        
        //Base case in NULL node returns (1) as it don't has camera and  if it returns 0 then the actuall end node of the tree will install camera which is not needed as it will be watched by its parent's camera.
        if(root == NULL){
            return 1;
        }
        
        int l = status (root->left,n);
        int r = status (root->right,n);
        
        //If any of the l or r is not watched install the camera and return the condition of the current node as have camera (2)
        if(l==0 || r==0){
            n++;
            return 2;
        }
        
        //If any of the l or r has camera then current node is being watched so don't install camera and return (1)
        if(l==2 || r==2){
            return 1;
        }
        
        //This gets executed if both l and r returns 1 i.e. is being watched but don't have cameras. So don't install camera and return (0)
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int n=0;
        
        //If root->right and root->left both don't have canera and are being watched then camera was not installed in recursion i.e. (0). As there is no parent node of it so install a camera here.
        if(status(root,n) == 0){
            n++;
        }
        return n;
    }
};
*/
class Solution {
public:
    //https://www.youtube.com/watch?v=2Gh5WPjAgJk
    
   int cnt=0;
    unordered_set<TreeNode*>s;
    void dfs(TreeNode* root,TreeNode* parent){
        if(root != NULL){
            dfs(root->left,root);
            dfs(root->right,root);
            if((parent==NULL && s.find(root) == s.end()) || s.find(root->left)== s.end() || s.find(root->right)== s.end()){
                cnt++;
                s.insert(root); 
                s.insert(root->left);
                s.insert(root->right);
                s.insert(parent);
            }
        }
        return;
    }
    
    
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        s.insert(NULL);  // this ensures that camera will not be inserted from the bottom most leavess 
                        // as for leaves root->left = null && root->right = null
        dfs(root,NULL);
        return cnt;
    }
};