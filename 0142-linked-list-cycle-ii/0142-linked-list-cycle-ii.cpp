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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode* ,int>mpp;
        ListNode* temp = head;
         
         while(temp!=NULL){
            if(mpp.find(temp)!=mpp.end()){
                return temp;
            }else{
                mpp[temp]=1;
                temp = temp->next;
            }
         }
         return NULL;
    }
};