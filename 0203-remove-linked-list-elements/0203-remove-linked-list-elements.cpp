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
    ListNode* removeElements(ListNode* head, int val) {
       if( head == NULL){
        return head;
       }
       if(head -> next == NULL && head-> val == val){
        return NULL;
       }
      
        ListNode* prev = NULL;
         ListNode* curr = head ;
         ListNode* forward = curr->next;
        while( curr !=  NULL){
            if(head -> val == val)
            {
                head = head -> next;
                prev = curr;
                curr = curr -> next;
            }
            if(curr -> val == val ){
                prev -> next = curr -> next;
                forward = curr -> next;
                curr -> next = NULL;
                curr = forward ;
               
            }else{
                    prev = curr;
                    
                    curr = curr -> next;

            }
                   
            
            
        }
        return head;
    }
};
