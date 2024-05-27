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

        //this has to be converted into array
        vector<int>arr;
        ListNode* temp = head;
        ListNode* temp2 =head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp ->next;
        }
        sort(arr.begin(),arr.end());
        //now again converting the elements of teh array into List
        for(int i=0;i<arr.size();i++){
            temp2->val = arr[i];
            temp2 = temp2->next;
        }
        return head;
    }
};