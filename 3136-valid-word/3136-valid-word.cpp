class Solution {
public:
    bool isValid(string word) {
          
          int n = word.size();
          if(n<3)return false;
          bool vowel = false;
          bool consonant = false;
          bool digits = false;
          for(int i=0;i<n;i++){
              char ch = word[i];
              if(ch >='0' && ch<='9'){
                 digits = true;
              }
             else if((ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ||
                  (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')){
                     vowel = true;
                  }

             else if((ch >='a' && ch<='z') || (ch>='A' && ch<='Z')){
                  consonant = true;
             } 
             else{
                 return false;
             }   

          }
        if(vowel && digits && consonant ||vowel && consonant) return true;
        return false;

    }
};