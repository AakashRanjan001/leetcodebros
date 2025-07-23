// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& a) {
//          int n = a.size();

//          stack<int>st;
//          st.push(a[0]);
//          for(int i=1;i<n;i++){
//              int curr = a[i];

//              if(( st.empty() && st.top() > 0 && curr>0)|| (st.top()<0 && curr<0)){
//                  st.push(curr);
//              }
// // case 2 : Collision idsposssig;e
//              if(st.top()>0 && curr<0 || st.top()<0 && curr>0){
//                   if(abs(curr) > abs(st.top())){
//                        a.erase(st.top());
//                   }
//                   else{
//                       a.erase(s.begin() + i);
//                   }
//              } 
//          }
//              vector<int>ans;
//           for(auto i:st){
//               ans.push_back(i);
//           }
//           reverse(ans.begin(),ans.end());
//           return ans;
//     }
// };

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            int curr = a[i];

            // Case 1: No collision possible, same direction or empty stack
            if (st.empty() || (st.top() < 0 && curr < 0) || (st.top() > 0 && curr > 0)) {
                st.push(curr);
            }
            // Case 2: Collision possible
            else {
                while (!st.empty() && st.top() > 0 && curr < 0) {
                    int top = st.top();
                    if (abs(top) < abs(curr)) {
                        st.pop(); // top destroyed, continue checking
                    } else if (abs(top) == abs(curr)) {
                        st.pop(); // both destroyed
                        curr = 0; // mark current as destroyed
                        break;
                    } else {
                        curr = 0; // current destroyed
                        break;
                    }
                }
                if (curr != 0) st.push(curr);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
