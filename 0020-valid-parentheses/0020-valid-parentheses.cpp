class Solution {
public:
    bool isValid(string s) {
         int n = s.size();
         stack<char>st;
         for(int i=0;i<n;i++){
             char ch = s[i];

             if(ch == '(' || ch == '{' || ch == '['){
                 st.push(ch);
             }
             else{
                 if(st.empty())return false;// matlabsabse pehle closing bracket aa gya
                 if(!st.empty()){
                     if(ch== ')' && st.top() == '(')st.pop();
                     else if(ch== '}' && st.top() == '{')st.pop();
                     else if(ch== ']' && st.top() == '[')st.pop();
                 }
                 else{
                     return false;// brackets not matching
                 }
             }
         }

         if(st.empty())return true;
         return false;
    }
};