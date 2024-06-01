
class Solution {
public:
    bool isValid(string word) {
        int n=word.length();
        if(n<3) return false;
        bool vowel=false;
        bool digit=false;
        bool consonant=false;

        for(int i=0;i<n;i++){
            char ch=word[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'  
        || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I'
        || ch == 'O' || ch == 'U') vowel=true;
            else if (ch>='0' && ch<='9') digit=true;
            else if(isalpha(ch)) consonant=true;
            else return false;
        }
        if(vowel && digit && consonant ||vowel && consonant) return true;
        return false;
    }
};