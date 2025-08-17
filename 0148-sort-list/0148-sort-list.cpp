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
    ListNode* sortList(ListNode* head) {

          if (head == nullptr || head->next == nullptr) return head;
         ListNode* temp = head;
         vector<int>curr;
         while(temp!=NULL){
             curr.push_back(temp->val);
             temp = temp->next;
         }
         sort(curr.begin(),curr.end());

         ListNode* ans = new ListNode(curr[0]);
         ListNode* tail = ans;
         for(int i=1;i<curr.size();i++){
              tail->next = new ListNode(curr[i]);
              tail = tail->next;

         }
         return ans;
    }
};