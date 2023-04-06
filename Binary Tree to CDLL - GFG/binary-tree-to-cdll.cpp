//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



void displayCList(Node *head)
{
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout <<endl;
    itr=itr->left;
    do{
        cout<<itr->data<<" ";
        itr=itr->left;
    }while(head!=itr);
    cout<<itr->data<<endl;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
     Node *concatenate(Node *leftList, Node *rightList)
    {    
        //if either of the lists is empty, we return the other list. 
        if (leftList == NULL)
            return rightList;
        if (rightList == NULL)
            return leftList;
            
        //storing the last node of left list.
        //KYUNKI YE CIRCULAR DDL H TO LAST NODE SIRF LEFT PTR EXCESS KRNE SE MILL JAYEGI
        Node *leftLast = leftList->left;
        //storing the last node of right list. 
        Node *rightLast = rightList->left;
        
        //connecting the last node of Left list with the first 
        //node of the right list.
        leftLast->right = rightList;
        rightList->left = leftLast;
        
        //left of first node points to the last node in the list.
        leftList->left = rightLast;
        
        //right of last node refers to the first node of the list.
        rightLast->right = leftList;
        return leftList;
    }
    
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
        if (root == NULL)
            return NULL;
        
        //calling the function for left and right subtrees recursively.    
        Node *left = bTreeToCList(root->left);
        Node *right = bTreeToCList(root->right);
        
        
        //making a circular linked list of single node. To do so, we make the  
        //right and left pointers of this node point to itself.
        root->left = root->right = root;
        
        
        //firstly, concatenating the left list with the list with 
        //single node i.e. current node. 
        //then concatenating the returned list with the right list. 
        return concatenate(concatenate(left, root), right);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution obj;
        Node *head = obj.bTreeToCList(root);
        displayCList(head);
    }
    return 0;
}








// } Driver Code Ends