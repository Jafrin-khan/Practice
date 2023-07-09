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
    
    void f(Node* root){
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;
        
        root->left->next = root->right;
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