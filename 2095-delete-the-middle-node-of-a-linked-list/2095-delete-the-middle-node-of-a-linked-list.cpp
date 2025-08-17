// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
         // length nikalo 
        //  ListNode* curr = head;
        //  int len = 0;
        //  while(curr!=NULL){
        //      len++;
        //      curr = curr ->next;
        //  }
        //  curr = head;
        //  for(int i=1;i<len/2;i++){
        //      curr = curr->next;

        //  }
        //  ListNode* toDelete = curr->next;
        //  curr->next = curr->next->next;
        //  delete toDelete;
        //  return head;

        //    if (head == nullptr || head->next == nullptr) {
        //     delete head;
        //     return nullptr;
        // }
        // ListNode* slow = head;
        // ListNode* fast = head;
        // ListNode* prev = NULL;

        // while(fast!=NULL && fast->next!=NULL){
        //      fast = fast->next->next;
        //      prev = slow;
        //      slow = slow->next;
             
        // }
        
        // prev->next = slow->next;
        // delete slow;
        // return head;

         if (head == NULL || head->next == NULL) {
        return NULL;
    }

    // Initialize slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;
    fast = head->next->next;

    // Move 'fast' pointer twice as fast as 'slow'
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete the middle node by skipping it
    slow->next = slow->next->next;
    return head;

    }
};

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
