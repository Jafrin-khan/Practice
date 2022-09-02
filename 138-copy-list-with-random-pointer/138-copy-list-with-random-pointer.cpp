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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL){
            return head;
        }
        
         Node* temp = head;
        
        //1st 
        while(temp != NULL){
           
         Node* nextList = temp->next;
         Node* node = new Node(temp->val);
         temp->next = node;
         node->next = nextList;
            temp = temp->next->next;  
            
        }
        
        //2nd
        temp = head;
        while(temp != NULL){
            
            if(temp->random){
            temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        
        
        //3rd
        temp = head;
        Node* newHead = new Node(0);
        Node* tail = newHead;
        
        while(temp != NULL){
            
          
            tail->next = temp->next;
            tail = tail->next;
            temp->next = temp->next->next;
            temp = temp->next;
            
        }
        
        return newHead->next;
        
    }
};