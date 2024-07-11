
class Solution {
public:
    string reverseParentheses(string s) 
    {
       string ans;
       stack<char> st;
       for(char ch:s)
       {
          st.push(ch);
          if(st.top() == ')')
          {
            string temp;
            st.pop();
             while(st.top() != '(')
             {
                temp += st.top();
                st.pop();
             }
             st.pop();
             for(char c:temp)
             {
                st.push(c);
             }
          }
       }   
       while(!st.empty())
          {
             ans += st.top();
             st.pop();
          }

          reverse(ans.begin(),ans.end());
          return ans;
    }
};