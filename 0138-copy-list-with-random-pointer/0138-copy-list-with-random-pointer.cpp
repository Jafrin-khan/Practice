/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//              01/07/2023 submission

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL) return head;
        
        Node* temp = head;
        
        //linking dup nodes
        while(temp != NULL){
            Node* newNode = new Node(temp->val);
            Node* nextNode = temp->next;
            temp->next = newNode;
            newNode->next = nextNode;
            
            temp = temp->next->next;
        }
        
        
        //linking random ptrs
        temp = head;
        while(temp != NULL){
            if(temp->random) temp->next->random = temp->random->next;/////////////
            temp = temp->next->next;
        }
        
        //segrating lists
        Node* ans = new Node(0);
        Node* toReturn = ans;
        temp = head;
        
        while(temp != NULL){
            ans->next = temp->next;
            ans = ans->next;
            
            temp->next = temp->next->next;
            temp = temp->next;///////////////////////
        }
        
        return toReturn->next;
    }
};