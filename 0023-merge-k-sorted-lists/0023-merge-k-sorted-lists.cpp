
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
class compare {
public:
    bool operator()(ListNode* &a , ListNode* &b) {
        return a->val > b->val; // Min-heap based on the value of ListNode
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minheap;

        int k = lists.size();
        if (k == 0) return NULL; // If the input lists are empty, return NULL

        // Insert the first element of each list into the heap
        for (int i = 0; i < k; i++) {
            if (lists[i] != nullptr) {  // Make sure we don't push NULL into the heap
                minheap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        // Process the heap and merge the lists
        while (!minheap.empty()) {
            ListNode* temp = minheap.top();
            minheap.pop();

            // If head is NULL, set the head and tail of the merged list
            if (head == NULL) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp; // Append to the result list
                tail = temp;
            }

            // If there is a next node in the list, push it to the heap
            if (temp->next != NULL) {
                minheap.push(temp->next);
            }
        }

        return head;
    }
};
