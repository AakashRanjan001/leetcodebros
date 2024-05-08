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
    ListNode* doubleIt(ListNode* head) {
        ListNode* cur = helper(head);
        if (cur && cur->val >= 10) 
            return new ListNode(cur->val/10, new ListNode(cur->val % 10, cur->next));
        
        return cur;
    }

    ListNode* helper(ListNode* head) {
        if (!head) return nullptr;
        ListNode* prev = helper(head->next);
        if (!prev) {
            head->val = 2 * head->val;

        } else {
            head->val = 2 * head->val + prev->val / 10;
            prev->val = prev->val % 10;
            head->next = prev;
        }
        return head;
    }
};
