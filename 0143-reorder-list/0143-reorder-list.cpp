class Solution {
public:
    int listSize(ListNode* temp){
        int size=0;
        while(temp){
            temp = temp->next;
            size++;
        }
        return size;
    }
    void solve(ListNode* &head,ListNode* revHead,int &k){
        if(revHead==NULL)
            return;
        solve(head,revHead->next,k);
        if(k==0){
            head->next = NULL;
            return;
        }
        revHead->next = head->next;
        head->next = revHead;
        head = head->next->next;
        k--;
    }
    void reorderList(ListNode* head) 
    {
        int size = listSize(head);
        size = size/2;
        solve(head,head,size);
    }
};
