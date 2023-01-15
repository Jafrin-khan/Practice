//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/

/*
pehle wala accepted ans pass isliye hora h kyunki TC faaltu hai

ye wali vid dekho bhaut sahi explain kr rkha hai

https://www.youtube.com/watch?v=7eBndROfUnw
*/

unordered_map<int,int> mp;
int findMinInd(int levelOrder[] , int si , int ei , int inorder[]){
    
    int ind = si;
    for(int i = si+1 ; i <= ei ; i++){
        if(mp[inorder[i]] < mp[inorder[ind]]){
            ind = i;
        }
    }
    
    return ind;
}

Node* f(int inorder[], int levelOrder[], int si, int ei){
     if(si > ei){
          return NULL;
      }
      
      int index = findMinInd(levelOrder , si , ei , inorder);
      
      Node* root = new Node(inorder[index]);
      
      if(si == ei){
          return root;
      }
      root->left = f(inorder , levelOrder , si , index-1);
      root->right = f(inorder , levelOrder , index+1 , ei);
      
      return root;
}

Node* buildTree(int inorder[], int levelOrder[], int si, int ei,int n)
{
//add code here.
     for(int i = 0 ; i < n ; i++){
         mp[levelOrder[i]] = i; 
     }
     return f(inorder , levelOrder , 0 , n-1);
      
      
}