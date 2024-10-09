class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int moves =0;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else{  // agar closing bracket hai 
                if(!st.empty()){ // agar stack empty nhi hai 
                      st.pop();
                }
                else{ // agar stack empty hai 
                     
                     moves ++;
                }
            }
          

        }

        if(!st.empty()){
            return st.size() + moves;
        }
        return moves;
        
    }
};