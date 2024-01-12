class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int n = s.length();
        int leftvowel =0;
        int rightvowel =0;
        
        for(int i=0;i<s.length()/2;i++){
            if(s[i]=='a'||s[i]=='A'|| s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U'){
                leftvowel++;
            }
        }
            for(int i=s.length()/2;i<s.length();i++){
                if(s[i]=='a'||s[i]=='A'|| s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U'){
                    rightvowel++;
                }
            }
            if(rightvowel==leftvowel){
                return true;
            }
        
        
        return false;
    }
};