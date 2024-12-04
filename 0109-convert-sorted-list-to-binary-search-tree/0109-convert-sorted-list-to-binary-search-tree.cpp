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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* SortedLLToBST(ListNode* &head, int cnt){
          //base case
          if(cnt<=0 || head == NULL){
            return NULL;
          }

          TreeNode* leftSubtree = SortedLLToBST(head , cnt -1-cnt/2);
          //left subtree ban gya 

          TreeNode* root = new TreeNode(head->val);
          // abb tak head hai woh mid mei aa gya hoga 

          root->left = leftSubtree;
          head = head->next;

          root->right = SortedLLToBST(head,cnt/2);
          return root;


    }

    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp = head;
        int cnt =0;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        return SortedLLToBST(head,cnt);
    }
};