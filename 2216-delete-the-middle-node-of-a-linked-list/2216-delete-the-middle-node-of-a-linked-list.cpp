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
    ListNode* deleteMiddle(ListNode* head) {
        //edge cases 
        if(head==NULL || head->next ==NULL){
            return NULL;
        }

        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL){
            fast = fast->next;
              if(fast!=NULL){
                temp = slow;
                fast = fast->next;
                slow = slow->next;
              }
        }
        // while(temp->next!=slow){
        //     temp = temp->next;
        // }
        temp -> next = slow->next;
        slow->next = NULL;
        delete slow;
        return head;


    }
};