/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp=new ListNode();
        ListNode* prev;
        temp=node;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp->val=temp->next->val;
            temp=temp->next;
        }
        prev->next=NULL;
        return;
    }
};
