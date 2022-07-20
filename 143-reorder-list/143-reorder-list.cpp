/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
   ListNode* reverse(ListNode* head){
           
       ListNode* current = head;
       ListNode* previous = NULL;
        
        while(current){
            ListNode* temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }
        
        return previous; 
    }
    
    int getLen(ListNode* head){
        
        ListNode* temp = head;
        int l = 0;
        
        while(temp != NULL){
            temp = temp->next;
            l++;
        }
        
        return l;
    }
    
    void reorderList(ListNode* head) {
        
         if(head == NULL || head->next == NULL){
            return;
        }

        int len = getLen(head);
        int mid = len/2;
       
        mid--;
        
        
        ListNode* temp = head;
        int i = 0;
        while(i < mid){
            temp = temp->next;
            i++;
        }
        
        //separating the two lists
        ListNode* secondHalf = reverse(temp->next);
        temp->next = NULL;
        
        ListNode* t1 = head;
        ListNode* t2 = secondHalf;
        
        ListNode* test = t2;
        
         
//             while(test != NULL){
//                 cout<<test->val<<endl;
            
//                 test = test->next;
               
            
//             }
            
        
       if(len%2 == 0){
          while(t1 != NULL && t2 != NULL){
            
            ListNode* v1 = t1->next;
            ListNode* v2 = t2->next;
            
            t1->next = t2;
            t2->next = v1;
            
            t1 = v1;
            t2 = v2;
            
        }
        }
       
        else{
            
            while(t1->next != NULL && t2->next != NULL){
            
            ListNode* v1 = t1->next;
            ListNode* v2 = t2->next;
            
            t1->next = t2;
            t2->next = v1;
            
            t1 = v1;
            t2 = v2;
            } 
            
            while(t2 != NULL){
         
                t1->next = t2;
                t2 = t2->next;
               
                t1 = t1->next;
            }
       
            
        }
        
    }
};