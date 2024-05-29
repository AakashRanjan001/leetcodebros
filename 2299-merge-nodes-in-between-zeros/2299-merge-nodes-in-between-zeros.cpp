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
    ListNode* mergeNodes(ListNode* head) {
        
      ListNode* curr = head->next;
      ListNode* dummy = new ListNode(1);
      ListNode* s = dummy;//jabb bhi dummy node banau toh ek pointer bana lena uska 

      while(curr!=NULL){
           int sum =0;
         while(curr->val!=0){
              sum+= curr->val;
              curr = curr->next;
         }
         
         ListNode* c = new ListNode(sum);
         dummy -> next = c;
         dummy = dummy -> next;
         curr = curr->next;
        
        


      }
       return s->next;


    }
};