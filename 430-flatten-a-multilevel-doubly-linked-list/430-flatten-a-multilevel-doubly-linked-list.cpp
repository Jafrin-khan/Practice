/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        if(head == NULL){
            return head;
        }
        
        Node* temp = head;
        
        while(temp->child == NULL){
            
            temp = temp->next;
            if(temp == NULL){
                return head;
            }
        }
     
      
            Node* toFix = flatten(temp->child);
            Node* toAttachNext = temp->next;
            
            temp->next = toFix;
            toFix->prev = temp;
            Node* traverse = toFix;
            
            while(traverse->next != NULL){
                traverse = traverse->next;
            }
            
           if(toAttachNext){
            traverse->next = toAttachNext;
            toAttachNext->prev = traverse;
           }
        
         else{
             traverse->next = NULL;
         }
        
        temp->child = NULL;
        
        return head;
        
    }
};