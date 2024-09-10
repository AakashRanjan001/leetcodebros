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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
  
    ListNode* curr=head;
        ListNode* nxt=head->next;
        while(nxt!=NULL){
            int gcd = __gcd(curr->val,nxt->val);
            ListNode* temp = new ListNode(gcd);
            curr->next = temp;
            temp->next =nxt;
            curr = nxt;
            nxt = nxt->next;
        }
        return head;
    
    }
};