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
    int getDecimalValue(ListNode* head) {
        //  ListNode* temp = head;
        //  vector<int>var;
        //  while(temp!=NULL){
        //      var.push_back(temp->val);
        //      temp = temp->next;

        //  }
        //  int sum =0;
        //  for(int i=0;i<var.size();i++){
        //      if(var[i] == 1){
        //          sum+=(pow(2,var.size()-i - 1));
        //      }
        //  }
        //  return sum;


        ListNode* temp = head;
        int ans =0;
        while(temp!=NULL){
            ans = (ans<<1)  + temp->val;
            temp = temp->next;
        }
        return ans;

    }
};