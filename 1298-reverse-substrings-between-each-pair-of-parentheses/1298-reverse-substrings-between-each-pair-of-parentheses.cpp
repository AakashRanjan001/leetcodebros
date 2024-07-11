class Solution {
public:
    string reverseParentheses(string s) {
        
        int n = s.size();
        stack<string>str; //for storing the string 
        stack<char>st;//for storing the parenethesis 
        string temp ="";
        int i=0;
        while(i<s.size()){

            if(s[i]=='('){
                st.push('(');
                str.push(temp);
                temp="";
                i++;
            }
            else if(s[i]==')'){
                reverse(temp.begin(),temp.end());
                temp = str.top() + temp;
                str.pop();
                st.pop();
                i++;
            }
            else{
                temp+=s[i];
                i++;
            }
        }
        return temp;
    }
};