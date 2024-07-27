class Solution {
public:
 
 bool isValid( char ch ){
   if(ch >='A'&& ch<='Z' || ch>='a'&&ch<='z' || ch>='0' && ch<='9'){
    return true;
   }
   else{
    return false;
   }

 }
 char tolower(char ch){
   if(ch>='A' && ch<='Z'){
      return (ch-'A')+'a';
   }
   else{
    return ch;
   }

 }



    
    bool isPalindrome(string s) {

    int i=0;
    int j= s.size()-1; 

    while(i<=j){
        if(isValid(s[i]) && isValid(s[j])){
            if(tolower(s[i])!=tolower(s[j])){
                 return false;
            }
            i++;
            j--;
        }
        else if(!isValid(s[i])){
            i++;
        }
        else if(!isValid(s[j])){
            j--;
        }

    } 
    return true;

    }
};