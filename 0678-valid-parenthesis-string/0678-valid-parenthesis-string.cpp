class Solution {
public:
    bool checkValidString(string s) {
        int open = 0,closed = 0;
        int n = s.length();
        
        for(int i = 0;i < s.length();++i){
           
            if (s[i] != ')'){
                open++;
            }else{open--;}
            if (s[n-i-1] != '('){
                closed++;
            }else{closed--;}
            if (open < 0 || closed < 0) return false;
  
        }
         
    return true;
    }
};

