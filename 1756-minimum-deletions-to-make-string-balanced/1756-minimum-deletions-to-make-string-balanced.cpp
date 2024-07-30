class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.size();
        stack<char>st;
        int ans =0;

        for(char ch:s){
            if(ch == 'b'){
                st.push(ch);
            }
            else if(ch == 'a'){
                if(!st.empty() &&  st.top()=='b'){
                    st.pop();
                    ans++;
                } 
                else{ // stack is empty 
                    st.push(ch);
                }
            }
        }
        return ans;
    }
};