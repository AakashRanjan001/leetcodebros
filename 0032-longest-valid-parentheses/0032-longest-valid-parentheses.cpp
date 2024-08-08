class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st; //we are pushing index so numeric
        st.push(-1);  // used for finding length thats why by default pehle hi insert kar diya 
        int maxi = 0;

        for(int i=0;i<s.size();i++){
            char ch = s[i];

            if(ch =='('){  //opening bracket mila toh push kar denge stack mei 
                st.push(i);
            }
            else{ //we got closing bracket
               st.pop();
               if(!st.empty()){ //clsosing bracket milne ke baad check kiya stack empty toh nhi haih 
                  int len = i - st.top();
                  maxi = max(len,maxi);
               }
               else {  // stack empty hai after we got the closing bracket
                
                  st.push(i);

               }

            }
        }
        return maxi;
    }
};