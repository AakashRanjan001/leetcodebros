class Solution {
public:
    int minAddToMakeValid(string s) {
         // This is my way 
        // int n = s.size();
        // int moves =0;
        // stack<char>st;
        // for(int i=0;i<n;i++){
        //     if(s[i] == '('){
        //         st.push(s[i]);
        //     }
        //     else{  // agar closing bracket hai 
        //         if(!st.empty()){ // agar stack empty nhi hai 
        //               st.pop();
        //         }
        //         else{ // agar stack empty hai 
                     
        //              moves ++;
        //         }
        //     }
        // }

        // if(!st.empty()){
        //     return st.size() + moves;
        // }
        // return moves;

        // BY USING THE COUNTING MECHANISM'
        int open =0;
        int closed =0;

        int n = s.size();
        for(char ch :s){
            if(ch =='('){
                open++;
            }
            else if(open>0){ // matched opening parenethesis 
                open--;
            }
            else{
                closed++; // unmatched closing parenethesis
            }
         
         
        }
        return open + closed;
        
    }
};