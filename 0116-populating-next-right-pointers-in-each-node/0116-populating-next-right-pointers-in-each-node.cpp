/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    /*
    TC = O(N)...simple tree traversal
    SC = O(N) or O(1)?? check from friends
    */
    void f(Node* root){
        
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return;
        }
        
        if(root->left){
            root->left->next = root->right;
        }
        
        if(root->next){
            root->right->next = root->next->left;
        }
        
        f(root->left);
        f(root->right);
    }
    Node* connect(Node* root) {
        f(root);
        
        return root;
    }
};