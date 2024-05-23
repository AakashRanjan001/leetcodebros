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
    ListNode* middleNode(ListNode* head) {
       ListNode*temp = head;
        int len =0;
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }
     int x = len/2 +1;
     temp = head;
     int cnt =0;
     while(temp){
        cnt++;
        if(cnt ==x){
            break;
        }
        temp= temp->next;
     }      
     return temp;
    }
};