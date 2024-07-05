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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*temp = head->next;
        int prev = head->val;
        int cnt = 1;// Node count;
        int crtcnt = 0;// Critical point count;
        vector<int>pos;
        while(temp->next!= NULL){
            cnt++;
            if(temp->val > prev && temp->val > temp->next->val){
                pos.push_back(cnt);
                crtcnt++;
            }
            else if(temp->val < prev && temp->val< temp->next->val){
                pos.push_back(cnt);
                crtcnt++;
            }

            prev = temp->val;
            temp = temp->next;
        }

        if(crtcnt <= 1) return {-1, -1};//Only one critical point;
        int maxi = pos.back()-pos[0];// since pos array is sorted according to the position.
        int mini = 1e9;

        for(int i = 0; i<pos.size()-1;i++){
            mini = min(mini, abs(pos[i]-pos[i+1]));
        }
        return {mini, maxi};
    }
};
