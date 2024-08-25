/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        
        if(root == NULL){
            return {};
        }
        stack<Node*>st;
        st.push(root);
        vector<int>ans;

        while(!st.empty()){
             Node* temp = st.top(); // step A
             //Step B: poppping out from the stack
             st.pop();
             
             ans.push_back(temp->val);// step C
             // calling for the children 
             for(int i=0;i<temp->children.size();i++){
                 st.push(temp->children[i]);
             }
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};