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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode* prev = NULL;
         ListNode* curr = head;
         int len = 0;

         while(curr!=NULL){
             len++;
             curr = curr->next;
         }
         // ye ek edge case hai jo mai bhul sakta hu 
         if(n == len){ // when we have to delete the nth node
              // we have to delete the first node from the start 
              ListNode* temp = head;
              temp = temp->next;
              delete head;
              return temp;
         }
         curr = head;
         
         for(int i=1;i<len-n;i++){
              curr = curr->next;
         }
         ListNode* todelete = curr->next;
         curr->next = curr->next->next;
         delete todelete;


         return head;
    }
};