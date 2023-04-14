//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


Node* f(int si , int ei , int post[]){
    
    if(si > ei) return NULL;
    
    Node* root = new Node(post[ei]);
    int idx = si;
    
    while(idx <= (ei-1) && post[idx] <= post[ei]) idx++;
    
    root->left = f(si , idx-1 , post);
    root->right = f(idx , ei-1 , post);
    
    return root;
}

Node *constructTree (int post[], int size)
{
    return f(0 , size-1 , post);
}