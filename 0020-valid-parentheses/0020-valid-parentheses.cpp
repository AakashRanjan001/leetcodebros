class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
    
    for(int i=0;i<s.size();i++){
        char ch = s[i];

      //openeing bracket 
      if(ch == '(' || ch == '{' || ch == '['){
         st.push(ch);     
      }
      


      else{  //closing bracket
      
           if(st.empty()){
             //closing bracket hai but stack empty hai matlab opening bracket nhi hai stack mei
             return false;
           }
           
           if(!st.empty()){  //agar stack empty nhi hai phir apon aage check kiye
            char topelement = st.top();//stack empty nhi hai
            if(topelement == '(' && ch ==')'){
                 //matching mil gy
                 st.pop();
           }
           else if(topelement == '{' && ch =='}'){
                 //matching mil gy
                 st.pop();
           }
           else if(topelement == '[' && ch ==']'){
                 //matching mil gy
                 st.pop();
           }
           else{ //brackets not matching
            return false;
           }
     }

 }

    }
    if(st.empty()){  //loop ke bahar aa gey matlab stack empty ho gya sab pop ho gya sabka pair mil gya 
      return true;
    }
    else{
        return false;
    }
        
    }
};